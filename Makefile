CFLAGS = -w -g -Wc++11-extensions 

INCLUDES = -Iincludes/ \

SOURCES = $(wildcard src/*.cpp) \
		  $(wildcard src/loader/*.cpp) \
		  $(wildcard src/parser/*.cpp) \

all: ${SOURCES}
	@mkdir -p bin/
	$(CXX) $(CFLAGS) $(INCLUDES) ${SOURCES} -o bin/ashc
