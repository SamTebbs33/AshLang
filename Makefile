CFLAGS = -g -w -std=c++11

INCLUDES = -Iincludes/ \

SOURCES = $(wildcard src/*.cpp) \
		  $(wildcard src/loader/*.cpp) \
		  $(wildcard src/parser/*.cpp) \
		  $(wildcard src/error/*.cpp) \
		  $(wildcard src/semantics/*.cpp) \
		  $(wildcard src/codegen/*.cpp) \

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

# Run in debug mode
debug:
	@echo "### Debugging ashc"
	@valgrind --track-origins=yes bin/ashc tests/Test

# Run
run:
	@echo "### Running ashc"
	@bin/ashc tests/Test

git:
	@echo "### Pulling and adding"
	@git pull
	@git add --all
	@echo "### Committing"
	@git commit -m "${M}"
	@echo "### Pushing"
	@git push
