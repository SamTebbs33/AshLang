build parser -o
g++ grammar/*.cpp src/classloader.cpp src/context.cpp  src/tests/parser-test.cpp -w -o bin/tests/parser-test 
