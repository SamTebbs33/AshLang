#include <error/errors.h>

unsigned int numErrors = 0;

void Error::error(const char* format, ...){
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    numErrors++;
}

void Error::parserError(const char* msg, char* currentFile, int lineNo){
    Error::error("SyntaxError:%s:%d: %s", currentFile, lineNo, msg);
}

unsigned int getNumErrors(){
    return numErrors;
}
