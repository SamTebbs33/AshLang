#ifndef FILE_CONTEXT_H
#define FILE_CONTEXT_H

#include "../grammar/tokens.h"
#include <string.h>

struct FileContext{
	std::string relPath;
	TokenQualifiedName* namespc;
};

namespace Context{
	FileContext* top();
	FileContext* pop();
	void push(FileContext* fc);
};

#endif
