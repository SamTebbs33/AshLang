#ifndef FILE_CONTEXT_H
#define FILE_CONTEXT_H

#include <parser/tokens.hpp>
#include <string.h>
#include <loader/member.hpp>

struct FileContext{
	std::string relPath;
	QualifiedName namespc;
	FileContext(std::string p, QualifiedName n);
};

namespace Context{
	FileContext top();
	FileContext pop();
	void push(FileContext fc);
	QualifiedName getNamespace();
};

#endif
