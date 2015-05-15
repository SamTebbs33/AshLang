#include <loader/classloader.hpp>
#include <util/util.hpp>
#include <util/platform.hpp>
#include <loader/member.hpp>
#include <error/errors.hpp>

char cwdBuf[FILENAME_MAX];
std::string compiledExtension = ".ashc", sourceExtension = ".ash", *classPath;
bool isInitialised = false;

void ClassLoader::init(){
	currentDir(cwdBuf, sizeof(cwdBuf));
	classPath = new std::string(getenv("ASH_PATH"));
	isInitialised = true;
}

std::string ClassLoader::getClassPath(){
	return *classPath;
}

bool ClassLoader::importClass(std::vector<std::string> vec){
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

bool ClassLoader::importClass(std::string qualifiedName){
	if(!isInitialised) return false;
	// Search current working directory
	AshFile* file = ClassLoader::searchDir(std::string(cwdBuf), qualifiedName);
	// Search in classpath
	if(!file){
		file = ClassLoader::searchDir(ClassLoader::getClassPath(), qualifiedName);}
	if(!file){
		Error::semanticError("Can't find class in classpath (" + qualifiedName +")");
	}else{
		parseLoadedFile(file);
	}
	delete file;
	return false;
}

void ClassLoader::parseLoadedFile(AshFile* file){

}

AshFile* ClassLoader::searchDir(std::string absPath, std::string qualifiedName){
	// If last char in the absolute path is not a path seperator char, then append one
	if(absPath.at(absPath.length()-1) != PATH_SEP) absPath += PATH_SEP;
	// Convert abspath and qualified name to a path
	std::string path = absPath+qualifiedName;
	// Make the path to a compiled class file
	std::string* compiledPath = new std::string(path+compiledExtension);
	// Attempt to open class file
	std::ifstream* stream = new std::ifstream(compiledPath->c_str(), std::ios_base::binary);
	if(stream->is_open()){
		// Compiled class file exists, so return it
		return new AshFile(false, compiledPath, stream);
	}
	// Compiled class file doesn't exist and its path is no longer needed
	delete compiledPath;

	// Attempt to find a source file instead
	std::string* srcPath = new std::string(path+sourceExtension);
	stream->open(srcPath->c_str(), std::ios_base::binary);
	if(stream->is_open()){
		return new AshFile(true, srcPath, stream);
	}
	// Neither the compiled class or source file could be found, so clean up and return
	delete srcPath;
	delete stream;
	return NULL;
}
