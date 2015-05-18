#ifndef CLASSIMPORTER_H
#define CLASSIMPORTER_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

struct AshFile {
	bool isSrc;
	std::string name;
	std::ifstream* stream;
	AshFile(bool src, std::string n, std::ifstream* s) : isSrc(src), stream(s), name(n){}
};

namespace ClassImporter {
	/*std::string sourceExtension, compiledExtension;
	char* cwdBuf;*/
	void init();
	std::string getCWD();
	std::string getJavaPath();
	std::string getAshPath();
	std::string getSourceExtension();
	bool importClass(std::vector<std::string> paths);
	bool importClass(std::string qualifiedName);
	AshFile* searchDir(std::string absPath, std::string qualifiedName);
	bool parseLoadedFile(AshFile* file);
}

#endif
