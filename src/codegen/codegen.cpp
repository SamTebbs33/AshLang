#include <codegen/codegen.hpp>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include <util/util.hpp>
#include <error/errors.hpp>

FILE* stream;
int indents = 0;
bool line = true;

void CodeGen::write(const char* fmt, ...){
    if(line){
        for(int i = 0; i < indents; i++) fprintf(stream, "\t");
        line = false;
    }
    va_list args;
    va_start(args, fmt);
    vfprintf(stream, fmt, args);
    va_end(args);
}

void CodeGen::newLine(){
    fprintf(stream, "\n");
    line = true;
}

void CodeGen::indent(){
    indents++;
}

void CodeGen::unindent(){
    if(indents > 0) indents--;
}

void CodeGen::gen(TokenFile* file, std::string filePath){
    stream = fopen((filePath+".java").c_str(), "w");
    if(stream){
        file->gen();
        fclose(stream);
    }else{
        Error::compilerError("Could not open code gen file (" + filePath + ".java)");
    }
}

void CodeGen::genMods(unsigned short mods){
    if(mods & EnumModifier::OVERRIDE){ CodeGen::write("@Override"); CodeGen::newLine();}
    if(mods & EnumModifier::PUBLIC) CodeGen::write("public ");
    else if(mods & EnumModifier::PRIVATE) CodeGen::write("private ");
    else if(mods & EnumModifier::PROTECTED) CodeGen::write("protected ");
    if(mods & EnumModifier::NATIVE) CodeGen::write("native ");
    if(mods & EnumModifier::FINAL) CodeGen::write("final ");
    if(mods & EnumModifier::STANDARD) CodeGen::write("standard ");
    if(mods & EnumModifier::STATIC) CodeGen::write("static ");

}
