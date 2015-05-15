#ifndef EXTERNS_H
#define EXTERNS_H

#include <stdio.h>

struct TokenFile;
extern int yyparse();
extern FILE* yyin;
extern void yyrestart(FILE* f);
extern int yydebug;
extern TokenFile* file;

#endif /* end of include guard: EXTERNS_H */
