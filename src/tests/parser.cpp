#include <stdio.h>
#include "../classloader.cpp"

#define println(a) printf("%s\n", a);

extern int yyparse();
extern FILE* yyin;
extern void yyrestart(FILE* f);
extern int yydebug;
char* currentFile;

int main(int argc, char *argv[]){
	if(argc < 2){
		println("Expected file path");
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	printf("Opening file: %s\n", argv[1]);
	if(f){
		//yydebug = 1;
		yyrestart(f);
		currentFile = argv[1];
		yyparse();
		printf("Parsed file");
	}else printf("Failed to open file");
	return 0;
}
