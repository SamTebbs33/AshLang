bison -d -t -o grammar/parser.cpp grammar/AshGrammar.y -Wnone
flex -o grammar/lexer.cpp grammar/AshLexGrammar.l
