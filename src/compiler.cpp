#include <stdlib.h>
#include <ctime>
#include <parser/externs.hpp>
#include <error/errors.hpp>
#include <loader/classimporter.hpp>
#include <loader/member.hpp>
#include <util/util.hpp>
#include <parser/tokens.hpp>
#include <codegen/codegen.hpp>

std::string currentFile;
const char* filePath;

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        Error::compilerError("Expected a file path argument (without extension)\n");
        return -1;
    }

    currentFile = std::string(argv[1]);
    filePath = (currentFile+ClassImporter::getSourceExtension()).c_str();
    yyin = fopen(filePath, "r");
    std::ifstream fileLineStream(filePath);
    yydebug = 0;

    if (yyin && fileLineStream.is_open()) {

        printf("### Parsing file: %s\n", filePath);
        yyrestart(yyin);
        clock_t t = clock();
        // Read in the source lines that are then used when reporting errors
        std::string line;
        while(std::getline(fileLineStream, line)) Error::pushSourceLine(line);
        fileLineStream.close();

        yyparse();
        t = clock() - t;
        double seconds = ((double)t) / CLOCKS_PER_SEC;
        printf("### Parsed file: %f ms\n", seconds * 1000);
        fclose(yyin);

        if(Error::getNumErrors() > 0) return 0;
        if(file){
            ClassImporter::init();
            file->preParse();
            file->analyse();
            //Members::printTypes();
            if(Error::getNumErrors() == 0){
                /*
                println("### Generating code");
                CodeGen::gen(file, currentFile);
                println("### Finished generating code");
                std::string command = "javac " + currentFile + ".java";
                println("### Compiling java");
                system(command.c_str());
                println("### Compiled java\n");
                command = "javap " + currentFile + ".class";
                system(command.c_str());
                */
            }
        }
        return 0;
    }else println("### Failed to open file");

    return -1;
}
