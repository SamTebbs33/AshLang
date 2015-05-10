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
    yyin = fopen(currentFile, "r");

    if (yyin) {
        yyrestart(yyin);
        yyparse();
        fclose(yyin);
        println("Parsed file");
        file.preParse();
        return 0;
    }else println("Failed to open file");

    return -1;
}
