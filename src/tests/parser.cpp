#include <stdio.h>
#define println(a) printf(a); printf("\n");

extern int yyparse();
extern FILE* yyin;
extern void yyrestart(FILE* f);

int main(int argc, char *argv[]){
	if(argc < 2){
		println("Expected file path");
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	printf("Opening file: %s\n", argv[1]);
	if(f){
		println("Opened file");
		yyin = f;
		yyrestart(f);
		yyparse();
		println("Parsed file");
	}else println("Failed to open file");
	return 0;
}
