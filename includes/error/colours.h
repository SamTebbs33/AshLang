#ifndef COLOURS_h
#define COLOURS_h

#include <curses.h>
#include <string>
#include <stdlib.h>

#define RESET std::string("\033[0m")
#define BLACK std::string("\033[30m") /* Black */
#define RED std::string("\033[31m") /* Red */
#define GREEN std::string("\033[32m") /* Green */
#define YELLOW std::string("\033[33m") /* Yellow */
#define BLUE std::string("\033[34m") /* Blue */
#define MAGENTA std::string("\033[35m") /* Magenta */
#define CYAN std::string("\033[36m") /* Cyan */
#define WHITE std::string("\033[37m") /* White */
#define BOLDBLACK std::string("\033[1m\033[30m") /* Bold Black */
#define BOLDRED std::string("\033[1m\033[31m") /* Bold Red */
#define BOLDGREEN std::string("\033[1m\033[32m") /* Bold Green */
#define BOLDYELLOW std::string("\033[1m\033[33m") /* Bold Yellow */
#define BOLDBLUE std::string("\033[1m\033[34m") /* Bold Blue */
#define BOLDMAGENTA std::string("\033[1m\033[35m") /* Bold Magenta */
#define BOLDCYAN std::string("\033[1m\033[36m") /* Bold Cyan */
#define BOLDWHITE std::string("\033[1m\033[37m") /* Bold White */

namespace Colours{

    bool colourTerm();

    std::string endColour(std::string str);

    std::string red(std::string str);

    std::string yellow(std::string str);

    std::string blue(std::string str);

    std::string magenta(std::string str);
}

#endif
