CXX = g++
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -Wformat -Wfloat-equal -W -Wreturn-type -pedantic-errors -Wundef
LDLIBS =
TARGETS = generate draw
 
all: $(TARGETS)

generate: Makefile cellular_terrain.o
	 $(CXX) $(CXXFLAGS) -o generate cellular_terrain.o generate.cpp

draw: Makefile cellular_terrain.o
	 $(CXX) $(CXXFLAGS) -o draw draw.cpp

clean:
	rm -f *.o

distclean: clean
	rm -f $(TARGETS)

real: distclean all
