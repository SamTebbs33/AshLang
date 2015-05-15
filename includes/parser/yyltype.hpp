#ifndef YYLTYPE_H
#define YYLTYPE_H

#define YYLTYPE_IS_DECLARED

typedef struct YYLTYPE{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;

#endif /* end of include guard: YYLTYPE_H */
