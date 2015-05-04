#ifndef CLASS_LOADER_H
#define CLASS_LOADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "platform.h"

struct AshFile{
	bool isSrc;
	std::string* name;
	std::ifstream* stream;
	AshFile(bool src, std::string* n, std::ifstream* s) : isSrc(src), stream(s), name(n){}
};

namespace ClassLoader {
	std::string sourceExtension = ".ash", compiledExtension = ".ashc";
	char cwdBuf[FILENAME_MAX];
	std::string getCWD();
	std::string getClassPath();
	bool importClass(std::string* qualifiedName);	
	AshFile* searchDir(std::string absPath, std::string* qualifiedName);
}

#endif
