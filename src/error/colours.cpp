#include <error/colours.hpp>

bool Colours::colourTerm() {
    std::string term = getenv("TERM");
	return term.find("xterm") != std::string::npos;
}

std::string Colours::endColour(std::string str) {
	return str + RESET;
}

std::string Colours::red(std::string str) {
	if(Colours::colourTerm()) return BOLDRED + Colours::endColour(str);
	else return str;
}

std::string Colours::yellow(std::string str) {
	if(Colours::colourTerm()) return BOLDYELLOW + Colours::endColour(str);
	else return str;
}

std::string Colours::blue(std::string str) {
	if(Colours::colourTerm()) return BOLDBLUE + Colours::endColour(str);
	else return str;
}

std::string Colours::magenta(std::string str) {
	if(Colours::colourTerm()) return BOLDMAGENTA + Colours::endColour(str);
	else return str;
}
