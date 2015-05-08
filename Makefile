CFLAGS = -w -g -Wc++11-extensions

INCLUDES = -Iincludes/ \

SOURCES = $(wildcard src/*.cpp) \
		  $(wildcard src/loader/*.cpp) \
		  $(wildcard src/parser/*.cpp) \

GRAMMARS = grammar/AshGrammar.y grammar/AshLexGrammar.l

# Build the parser and compiler
build: ${SOURCES}
	@mkdir -p bin/
	@make parser
	@$(CXX) $(CFLAGS) $(INCLUDES) ${SOURCES} -o bin/ashc

# Build the parser
parser: ${GRAMMARS}
	@mkdir -p src/parser
	@bison -d -Wnone grammar/AshGrammar.y -o src/parser/parser.cpp
	@flex -o src/parser/lexer.cpp grammar/AshLexGrammar.l
	@mv src/parser/parser.hpp includes/parser/parser.hpp

# Build and run
br:
	make build
	make r

# Build and run in debug mode
bd:
	make build
	make d

# Tun in debug mode
d:
	@sudo lldb bin/ashc tests/syntax.ash

# Run
r:
	@bin/ashc tests/syntax.ash
