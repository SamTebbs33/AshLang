#include <loader/classimporter.hpp>
#include <loader/classloader.hpp>
#include <util/util.hpp>
#include <util/platform.hpp>
#include <loader/member.hpp>
#include <error/errors.hpp>
#include <util/enums.hpp>

char cwdBuf[FILENAME_MAX];
std::string compiledExtension = ".class", sourceExtension = ".ash", ashPath, javaPath;
bool isInitialised = false;

void ClassImporter::init(){
	currentDir(cwdBuf, sizeof(cwdBuf));
	ashPath = std::string(getenv("ASH_PATH"));
	javaPath = std::string(getenv("JAVA_HOME"));
	isInitialised = true;
}

std::string ClassImporter::getAshPath(){
	return ashPath;
}

std::string ClassImporter::getJavaPath(){
	return javaPath;
}

std::string ClassImporter::getSourceExtension(){
	return sourceExtension;
}

bool ClassImporter::importClass(std::vector<std::string> vec){
	if(!isInitialised) return false;
	std::string path = "";
	int x = 0;
	foreach(it, vec){
		// Append path segment
		path += *it;
		// Append path seperator if needed
		if(x++ < vec.size()-1) path += PATH_SEP;
	}
	return importClass(path);
}

bool ClassImporter::importClass(std::string qualifiedName){
	if(!isInitialised) return false;
	bool success = false;
	// Search current working directory
	AshFile* file = ClassImporter::searchDir(std::string(cwdBuf), qualifiedName);
	println("Looked in current dir");
	if(file){
		// Found in current directory
		return parseLoadedFile(file);
	}else {
		// Search in ash path
		file = ClassImporter::searchDir(ClassImporter::getAshPath(), qualifiedName);
		println("Looked in ash path");
	}

	if(file){
		// Found in ash path
		return parseLoadedFile(file);
	}else{
		// Search in the jdk path
		file = ClassImporter::searchDir(ClassImporter::getJavaPath(), qualifiedName);
		println("Looked in java");
	}

	if(file){
		// Found in jdk path
		return parseLoadedFile(file);
	}else{
		// Can't be found
		Error::semanticError("Can't find class in classpath (" + qualifiedName +")");
	}

	return false;
}

bool ClassImporter::parseLoadedFile(AshFile* file){
	printf("parsing loaded file\n");
	if(!file->isSrc){
		printf("!isSrc\n");
		ClassFile* clsFile = ClassLoader::loadClass(file);

		// Parser the type (class, interface or enum)
		EnumType::type type;
		if(clsFile->access_flags & 0x4000) type = EnumType::ENUM;
		else if(clsFile->access_flags & 0x0200) type = EnumType::PROTOCOL;
		else type = EnumType::CLASS;

		// Parse the modifiers
		ModifiersInt mods = 0;
		if(clsFile->access_flags & 0x0001) mods |= EnumModifier::PUBLIC;
		if(clsFile->access_flags & 0x0010) mods |= EnumModifier::FINAL;
		if(clsFile->access_flags & 0x0400) mods |= EnumModifier::ABSTRACT;

		// Read in the class qualified name
		QualifiedName name;
		printf("This class: %u\n", clsFile->this_class);
		constant_class* clsInfo = (constant_class*)clsFile->constant_pool[clsFile->this_class];
		printf("Class info name index: %u\n", clsInfo->name_index-2);
		constant_utf8* clsName = (constant_utf8*)clsFile->constant_pool[clsInfo->name_index-2];
		//printf("Class name tag: %u\n", clsFile->constant_pool[((constant_class*)clsFile->constant_pool[clsFile->this_class])->name_index]->tag);
		std::string fullName = "";
		for(int i = 0; i < clsName->length; i++){
			char ch = (char)clsName->bytes[i];
			printf("%c\n", ch);
			if(ch == '/'){
				if(fullName != "") name.add(fullName);
				fullName = "";
			}else fullName += ch;
		}
		name.add(fullName);
		printf("Made name: %s\n", name.fullName.c_str());

		Members::addAndEnterType(new Type(mods, name, type));
	}
	return false;
}

AshFile* ClassImporter::searchDir(std::string absPath, std::string qualifiedName){
	// If last char in the absolute path is not a path seperator char, then append one
	if(absPath.at(absPath.length()-1) != PATH_SEP) absPath += PATH_SEP;
	// Convert abspath and qualified name to a path
	std::string path = absPath+qualifiedName;
	// Make the path to a compiled class file
	std::string compiledPath = std::string(path+compiledExtension);
	printf("searching for class: %s\n", compiledPath.c_str());
	// Attempt to open class file
	std::ifstream* stream = new std::ifstream(compiledPath.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
	if(stream->is_open()){
		// Compiled class file exists, so return it
		return new AshFile(false, compiledPath, stream);
	}

	// Attempt to find a source file instead
	std::string srcPath = std::string(path+sourceExtension);
	printf("searching for source: %s\n", srcPath.c_str());
	stream->open(srcPath.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
	if(stream->is_open()){
		return new AshFile(true, srcPath, stream);
	}
	// Neither the compiled class or source file could be found, so clean up and return
	return NULL;
}
