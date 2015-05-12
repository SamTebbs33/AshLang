#ifndef CLASS_LOADER_H
#define CLASS_LOADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <util/platform.hpp>
#include <parser/tokens.hpp>

struct AshFile{
	bool isSrc;
	std::string* name;
	std::ifstream* stream;
	AshFile(bool src, std::string* n, std::ifstream* s) : isSrc(src), stream(s), name(n){}
};

namespace ClassLoader {
	/*std::string sourceExtension, compiledExtension;
	char* cwdBuf;*/
	void init();
	std::string getCWD();
	std::string getClassPath();
	bool importClass(std::vector<std::string> paths);
	bool importClass(std::string qualifiedName);
	AshFile* searchDir(std::string absPath, std::string qualifiedName);
	void parseLoadedFile(AshFile* file);
}

#endif
