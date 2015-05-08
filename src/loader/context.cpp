#include "loader/context.h"

#define STACK_SIZE 1024

FileContext* contextStack[STACK_SIZE];
unsigned short stackPtr = 0;

FileContext::FileContext(std::string p, QualifiedName* n) : relPath(p), namespc(n) {

}

FileContext* Context::top(){
 	return stackPtr >= 1 ? contextStack[stackPtr-1] : NULL;
}

FileContext* Context::pop(){
	return stackPtr >= 1 ? contextStack[--stackPtr] : NULL;
}

void Context::push(FileContext* c){
	if(stackPtr < STACK_SIZE) contextStack[stackPtr++] = c;
}

QualifiedName* Context::getNamespace(){
    return Context::top()->namespc;
}
