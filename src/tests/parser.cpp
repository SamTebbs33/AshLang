#include <stdio.h>

extern int yyparse();
extern FILE* yyin;
extern void yyrestart(FILE* f);

int main(int argc, char *argv[])
{
	FILE* f = fopen(argv[1], "r");
	printf("Reading file: %s\n", argv[1]);
	if(f){
		printf("Opened file\n");
		yyin = f;
		yyrestart(f);
		yyparse();
	}
	return 0;
}
