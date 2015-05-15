#include <stdio.h>
#include <ctime>
#include <parser/externs.hpp>
#include <error/errors.hpp>
#include <loader/classloader.hpp>
#include <loader/member.hpp>
#include <util/util.hpp>
#include <parser/tokens.hpp>

const char* currentFile;

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        Error::compilerError("Expected a file path argument\n");
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
        double seconds = ((double)t) / CLOCKS_PER_SEC;
        printf("### Parsed file: %f ms\n", seconds * 1000);
        fclose(yyin);

        if(Error::getNumErrors() > 0) return 0;
        if(file){
            ClassLoader::init();
            file->preParse();
            file->analyse();
            Members::printTypes();
        }
        return 0;
    }else println("### Failed to open file");

    return -1;
}
