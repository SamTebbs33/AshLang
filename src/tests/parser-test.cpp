#include <stdio.h>
#include "../classloader.h"
#include "../../grammar/tokens.h"
#include "../util.h"

extern int yyparse();
extern FILE* yyin;
extern void yyrestart(FILE* f);
extern int yydebug;
char* currentFile;
extern TokenFile* file;

int main(int argc, char *argv[]){
	if(argc < 2){
		println("Expected file path");
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	printf("Opening file: %s\n", argv[1]);
	if(f){
		ClassLoader::init();
		//yydebug = 1;
		yyrestart(f);
		currentFile = argv[1];
		yyparse();
		println("Parsed file");
		if(file) foreachp(it, file->imports->imports) (*it)->preParse();
	}else println("Failed to open file");
	return 0;
}
