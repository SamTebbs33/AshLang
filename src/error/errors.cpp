#include <error/errors.hpp>

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
void Error::parserError(const char* msg, YYLTYPE location){
    Error::error(Colours::red("Error"), ":%s:%d-%d: %s\n", currentFile, location.first_line, location.first_column, msg);
}

/**
 * Emit a semantic error
 * @type {void}
 */
void Error::semanticError(std::string str){
    //TODO: Report line
    Error::error(Colours::red("Error"), ":%s: %s\n", currentFile, str.c_str());
}

unsigned int Error::getNumErrors(){
    return numErrors;
}
