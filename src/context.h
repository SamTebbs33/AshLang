#ifndef FILE_CONTEXT_H
#define FILE_CONTEXT_H

#include "../grammar/tokens.h"
#include <string.h>

namespace Contexts{
	void setContext(Context* c);
	void addContext(Context* c);
}

class Context{
public:
	Context* parent;
	Context();
};

class FileContext : Context{
public:
	TokenQualifiedName* namespc;
	std::string filePath;
	FileContext(TokenQualifiedName* n, std::string f);
};

#endif
