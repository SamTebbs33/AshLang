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

QualifiedName toQualifiedName(constant_utf8* utf8){
	QualifiedName name;
	std::string progress = "";
	// Convert the class to a qualified name
	for(int i = 0; i < utf8->length; i++){
		char ch = (char)utf8->bytes[i];
		if(ch == '/'){
			if(progress != "") name.add(progress);
			progress = "";
		}else progress += ch;
	}
	name.add(progress);
	return name;
}

JavaClass::JavaClass(ClassFile* clsFile){
	if(clsFile->access_flags & 0x4000) type = EnumType::ENUM;
	else if(clsFile->access_flags & 0x0200) type = EnumType::PROTOCOL;
	else type = EnumType::CLASS;

	// Parse the modifiers
	if(clsFile->access_flags & 0x0001) mods |= EnumModifier::PUBLIC;
	if(clsFile->access_flags & 0x0010) mods |= EnumModifier::FINAL;
	if(clsFile->access_flags & 0x0400) mods |= EnumModifier::ABSTRACT;

	// Read in the class qualified name
	constant_class* clsInfo = (constant_class*)clsFile->constant_pool[clsFile->this_class];
	constant_utf8* clsName = (constant_utf8*)clsFile->constant_pool[clsInfo->name_index];
	name = toQualifiedName(clsName);

	// Read in super class and interfaces
	if(clsFile->super_class > 0){ // If the class is not Object
		constant_class* superInfo = (constant_class*)clsFile->constant_pool[clsFile->super_class];
		super = toQualifiedName((constant_utf8*)clsFile->constant_pool[superInfo->name_index]);
	}
	interfaceCount = clsFile->interface_count;
	interfaces = new QualifiedName[interfaceCount];
	for(int i = 0; i < interfaceCount; i++){
		constant_class* interfaceInfo = (constant_class*)clsFile->constant_pool[clsFile->interfaces[i]];
		interfaces[i] = toQualifiedName((constant_utf8*)clsFile->constant_pool[interfaceInfo->name_index]);
	}

	// Read in fields
	// Read in methods
}

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
	if(file){
		// Found in current directory
		return parseLoadedFile(file);
	}else {
		// Search in ash path
		file = ClassImporter::searchDir(ClassImporter::getAshPath(), qualifiedName);
	}

	if(file){
		// Found in ash path
		return parseLoadedFile(file);
	}else{
		// Search in the jdk path
		file = ClassImporter::searchDir(ClassImporter::getJavaPath(), qualifiedName);
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
	if(!file->isSrc){
		JavaClass cls(ClassLoader::loadClass(file));

		Members::addAndEnterType(new Type(cls.mods, cls.name, cls.type));
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
	// Attempt to open class file
	std::ifstream* stream = new std::ifstream(compiledPath.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
	if(stream->is_open()){
		// Compiled class file exists, so return it
		return new AshFile(false, compiledPath, stream);
	}

	// Attempt to find a source file instead
	std::string srcPath = std::string(path+sourceExtension);
	stream->open(srcPath.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
	if(stream->is_open()){
		return new AshFile(true, srcPath, stream);
	}
	// Neither the compiled class or source file could be found, so clean up and return
	return NULL;
}
