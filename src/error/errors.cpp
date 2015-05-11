#include <error/errors.h>

unsigned int numErrors = 0;
extern char* currentFile;

void Error::error(std::string errType, const char* format, ...){
    fprintf(stderr, "%s", errType.c_str());
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    numErrors++;
}

void Error::compilerError(std::string msg){
    Error::error(Colours::red("Error"), ": %s\n", msg.c_str());
}

/**
 * Emit a parser (syntax) error
 * @type {void}
 */
void Error::parserError(const char* msg, int lineNo){
    Error::error(Colours::red("Error"), ":%s:%d: %s\n", currentFile, lineNo, msg);
}

/**
 * Emit a semantic error
 * @type {void}
 */
void Error::semanticError(std::string str){
    //TODO: Report line
    Error::error(Colours::red("Error"), ":%s: %s\n", currentFile, str.c_str());
}

unsigned int getNumErrors(){
    return numErrors;
}
