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

struct TypeContext{
	Type* type;
	TypeContext(Type* t);
	TypeContext();
};

namespace Context{
	FileContext top();
	FileContext pop();
	void push(FileContext fc);
	void enterTypeContext(TypeContext tc);
	void exitTypeContext();
	QualifiedName getNamespace();
};

#endif
