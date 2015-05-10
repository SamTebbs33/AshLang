#include "loader/context.h"
#include <stack>

#define STACK_SIZE 1024

std::stack<FileContext>* stack = new std::stack<FileContext>();

FileContext::FileContext(std::string p, QualifiedName n) : relPath(p), namespc(n) {

}

FileContext Context::top(){
 	return stack->top();
}

FileContext Context::pop(){
	FileContext c = top();
    stack->pop();
    return c;
}

void Context::push(FileContext c){
	stack->push(c);
}

QualifiedName Context::getNamespace(){
    return Context::top().namespc;
}
