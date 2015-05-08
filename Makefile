CFLAGS = -w -g -Wc++11-extensions

INCLUDES = -Iincludes/ \

SOURCES = $(wildcard src/*.cpp) \
		  $(wildcard src/loader/*.cpp) \
		  $(wildcard src/parser/*.cpp) \

GRAMMARS = grammar/AshGrammar.y grammar/AshLexGrammar.l

all: ${SOURCES}
	@mkdir -p bin/
	@make parser
	@$(CXX) $(CFLAGS) $(INCLUDES) ${SOURCES} -o bin/ashc

parser: ${GRAMMARS}
	@mkdir -p src/parser
	@bison -d -Wnone grammar/AshGrammar.y -o src/parser/parser.cpp
	@flex -o src/parser/lexer.cpp grammar/AshLexGrammar.l
	@mv src/parser/parser.hpp includes/parser/parser.hpp
