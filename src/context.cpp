#include "context.h"

Context* currentContext;

void Contexts::setContext(Context* c){
	currentContext = c;
}

void Contexts::addContext(Context* c){
	if(currentContext){
		c->parent = currentContext;
	}
	setContext(c);
}

Context::Context() : parent(c){

}

FileContext::FileContext(TokenQualifiedName* n, std::string p) : namespc(n), filePath(p){

}
