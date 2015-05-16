#include <error/errors.hpp>
#include <error/colours.hpp>
#include <parser/yyltype.hpp>
#include <vector>

std::vector<std::string> lines;
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
void Error::parserError(const char* msg, YYLTYPE* location){
    Error::error(Colours::red("Error"), " [%s:%d-%d] %s\n", currentFile, location->first_line, location->first_column, msg);
    fprintf(stderr, "%s\n", lines.at(location->first_line-1).c_str());
    std::string locationIndicator;
    // Print out the message that shows the location of the error on the source line
    // Add 3 to the termination condition of this loop to handle the tab printed above
    for(int i = 0; i < location->first_column - 1; i++) locationIndicator += " ";
    locationIndicator += "^";
    // If there is actually any space between the first and last columns, otherwise just print the ^ character
    if(location->last_column - location->first_column > 0){
        for(int i = location->first_column; i < location->last_column - 1; i++) locationIndicator += "-";
        locationIndicator += "^";
    }
    fprintf(stderr, "%s\n", locationIndicator.c_str());
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

void Error::pushSourceLine(std::string line){
    lines.push_back(line);
}
