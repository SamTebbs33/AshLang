#include "classloader.h"
#include "util.h"

char cwdBuf[FILENAME_MAX];
std::string compiledExtension = "", sourceExtension = "";

void ClassLoader::init(){
	currentDir(cwdBuf, sizeof(cwdBuf));
	sourceExtension = ".ash";
	compiledExtension = ".ashc";
}

std::string ClassLoader::getClassPath(){
	return std::string(getenv("ASH_PATH"));
}

/*std::string ClassLoader::getCWD(){
	if(currentDir(ClassLoader::cwdBuf, sizeof(ClassLoader::cwdBuf))){
		return std::string(ClassLoader::cwdBuf);
	}else return "";
}*/

bool ClassLoader::importClass(std::vector<std::string*> vec){
	std::string path = "";
	int x = 0;
	foreach(it, vec){
		path += **it;
		if(x++ < vec.size()-1) path += PATH_SEP;
	}
	return importClass(&path);
}

bool ClassLoader::importClass(std::string* qualifiedName){
	printf("Importing: %s\n", qualifiedName->c_str());
	// Search current working directory
	AshFile* file = ClassLoader::searchDir(cwdBuf, qualifiedName);
	// Search in classpath
	if(!file) file = ClassLoader::searchDir(ClassLoader::getClassPath(), qualifiedName);
	if(!file){
		//TODO: error
		printf("Can't import class: %s\n", qualifiedName->c_str());
	}
	//TODO: Do import process
	return false;
}

AshFile* ClassLoader::searchDir(std::string absPath, std::string* qualifiedName){
	// If last char in the absolute path is not a path seperator char, then append one
	if(absPath.at(absPath.length()-1) != PATH_SEP) absPath += PATH_SEP;
	// Convert abspath and qualified name to a path
	std::string path = absPath+*qualifiedName;

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

	// The compiled or source file couldn't be found so clean up and return
	delete srcPath;
	delete stream;
	return NULL;
}
