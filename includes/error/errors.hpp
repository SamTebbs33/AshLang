#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdarg.h>
#include <string>

struct YYLTYPE;

namespace Error {
    void parserError(const char* msg, YYLTYPE* location);
    void semanticError(std::string msg);
    void compilerError(std::string msg);
    void error(std::string errType, const char* format, ...);
    unsigned int getNumErrors();
} /* Error */

#endif /* end of include guard: ERRORS_H */
