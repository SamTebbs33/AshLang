#include <parser/externs.h>
#include <util/util.h>
#include <loader/classloader.h>
#include <stdio.h>
#include <loader/member.h>
#include <error/errors.h>
#include <ctime>

const char* currentFile;

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        Error::error("!: Expected a file path argument\n");
        return -1;
    }

    currentFile = argv[1];
    yyin = fopen(currentFile, "r");
    yydebug = 0;

    if (yyin) {
        printf("### Parsing file: %s\n", currentFile);
        yyrestart(yyin);
        clock_t t = clock();
        yyparse();
        t = clock() - t;
        printf("### Parsed file: %f seconds\n", ((float)t) / CLOCKS_PER_SEC);
        fclose(yyin);
        //ClassLoader::init();
        //file.preParse();
        //Members::printTypes();
        return 0;
    }else println("### Failed to open file");

    return -1;
}
