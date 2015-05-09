#include <parser/externs.h>
#include <util/util.h>
#include <loader/classloader.h>
#include <stdio.h>
#include <loader/member.h>

const char* currentFile;

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        println("File path expected");
        return -1;
    }

    currentFile = argv[1];
    printf("Parsing file: %s\n", currentFile);
    FILE* f = fopen(currentFile, "r");

    if (f) {
        yyin = f;
        yyrestart(f);
        yyparse();
        println("Parsed file");
        if(file){
            // Temporaily commented out as lldb throws an exception when getenv is used
            // ClassLoader::init();
            println("Initialised class loader");
            file->preParse();
            println("Pre-parsed");
            printf("Type: %s\n", Members::getCurrentType()->name->getShortName()->c_str());
            if(Members::getCurrentType()->funcs->size() > 0) printf("Func: %s\n", Members::getCurrentType()->funcs->at(0)->id->c_str());
        }
        return 0;
    }else println("Failed to open file");

    return -1;
}
