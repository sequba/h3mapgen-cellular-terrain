CXX = g++
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -Wformat -Wfloat-equal -W -Wreturn-type -pedantic-errors -Wundef
LDLIBS =
TARGETS = generate draw
 
all: $(TARGETS)

generate: Makefile board.o cellular_terrain.o
	 $(CXX) $(CXXFLAGS) -o generate board.o cellular_terrain.o generate.cpp

draw: Makefile board.o
	 $(CXX) $(CXXFLAGS) -o draw board.o draw.cpp

clean:
	rm -f *.o

distclean: clean
	rm -f $(TARGETS)

real: distclean all
