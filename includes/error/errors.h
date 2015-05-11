#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdarg.h>
#include <parser/tokens.h>
#include <error/colours.h>

namespace Error {
    void parserError(const char* msg, int lineNo);
    void semanticError(std::string msg);
    void compilerError(std::string msg);
    void error(std::string errType, const char* format, ...);
    unsigned int getNumErrors();
} /* Error */

#endif /* end of include guard: ERRORS_H */
