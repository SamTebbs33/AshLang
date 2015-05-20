#ifndef CLASSIMPORTER_H
#define CLASSIMPORTER_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <loader/member.hpp>
#include <util/enums.hpp>

struct ClassFile;

struct AshFile {
	bool isSrc;
	std::string name;
	std::ifstream* stream;
	AshFile(bool src, std::string n, std::ifstream* s) : isSrc(src), stream(s), name(n){}
};

struct JavaMethod {
	QualifiedName returnType;
	int arrDims;
};

struct JavaField {
	/* data */
};

struct JavaClass {
	EnumType::type type;
	QualifiedName name;
	QualifiedName super;
	int interfaceCount;
	QualifiedName* interfaces;
	ModifiersInt mods = 0;
	int methodCount;
	JavaMethod* methods;
	int fieldCount;
	JavaField* fields;
	JavaClass(ClassFile* cls);
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
