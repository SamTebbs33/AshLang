build parser -o
g++ -g -o bin/tests/parser-test grammar/parser.cpp grammar/lexer.cpp src/tests/parser.cpp grammar/tokens.cpp -w
