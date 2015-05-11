#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdarg.h>

namespace Error {
    void parserError(const char* msg, char* currentFile, int lineNo);
    void error(const char* format, ...);
    unsigned int getNumErrors();
} /* Error */

#endif /* end of include guard: ERRORS_H */
