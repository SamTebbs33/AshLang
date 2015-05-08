#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#define println(a) printf("%s\n", a);
#define foreach(x, y) for(auto x = y.begin(); x != y.end(); x++)
#define foreachp(x, y) for(auto x = y->begin(); x != y->end(); x++)

#endif
