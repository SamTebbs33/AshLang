#include <stdio.h>

extern int yyparse();
extern FILE* yyin;
extern void yyrestart(FILE* f);

int main(int argc, char *argv[])
{
	FILE* f = fopen(argv[1], "r");
	if(f){
		yyrestart(f);
		yyparse();
	}
	return 0;
}
