#include <loader/context.hpp>
#include <stack>

#define STACK_SIZE 1024

std::stack<FileContext>* stack = new std::stack<FileContext>();
TypeContext currentTypeContext;
FuncContext currentFuncContext;
bool inTypeContext = false, inFuncContext = false;

FileContext::FileContext(std::string p, QualifiedName n) : relPath(p), namespc(n) {}

TypeContext::TypeContext(Type* type) : type(type){}
TypeContext::TypeContext(){}

FuncContext::FuncContext(FuncSignature* sig) : sig(sig){}
FuncContext::FuncContext(){}

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

void Context::enterTypeContext(TypeContext tc){
    currentTypeContext = tc;
    inTypeContext = true;
}

void Context::exitTypeContext(){
    inTypeContext = false;
}

void Context::enterFuncContext(FuncContext fc){
    currentFuncContext = fc;
    inFuncContext = true;
}

void Context::exitFuncContext(){
    inFuncContext = false;
}

TypeContext Context::getTypeContext(){
    return currentTypeContext;
}

FuncContext Context::getFuncContext(){
    return currentFuncContext;
}

bool Context::inType(){
    return inTypeContext;
}

bool Context::inFunc(){
    return inFuncContext;
}

QualifiedName Context::getNamespace(){
    return Context::top().namespc;
}
