CFLAGS = -std=c++14 -g -w

INCLUDES = -Iincludes/ \

SOURCES = $(wildcard src/*.cpp) \
		  $(wildcard src/loader/*.cpp) \
		  $(wildcard src/parser/*.cpp) \

GRAMMARS = grammar/AshGrammar.y grammar/AshLexGrammar.l

# @ is used to silence commands

# Build the parser and compiler
build: ${SOURCES}
	@mkdir -p bin/
	@make parser
	@echo "### Building compiler"
	@g++ $(CFLAGS) $(INCLUDES) ${SOURCES} -o bin/ashc

# Build the parser
parser: ${GRAMMARS}
	@echo "### Building parser"
	@mkdir -p src/parser
	@bison -d -Wnone grammar/AshGrammar.y -o src/parser/parser.cpp
	@flex -o src/parser/lexer.cpp grammar/AshLexGrammar.l
	@mv src/parser/parser.hpp includes/parser/parser.hpp

# Build and run
build-run:
	@make build
	@make run

# Build and run in debug mode
build-debug:
	@make build
	@make debug

# Run in debug mode
debug:
	@echo "### Debugging ashc"
	@valgrind --track-origins=yes bin/ashc tests/syntax.ash

# Run
run:
	@echo "### Running ashc"
	@bin/ashc tests/syntax.ash
