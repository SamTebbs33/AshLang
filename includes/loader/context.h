#ifndef FILE_CONTEXT_H
#define FILE_CONTEXT_H

#include "parser/tokens.h"
#include <string.h>

struct FileContext{
	std::string relPath;
	TokenQualifiedName* namespc;
	FileContext(std::string p, TokenQualifiedName* n);
};

namespace Context{
	FileContext* top();
	FileContext* pop();
	void push(FileContext* fc);
};

#endif
