CXX = g++
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -Wformat -Wfloat-equal -W -Wreturn-type -pedantic-errors -Wundef
LDLIBS =
TARGETS = generate draw random randomize facade_test
 
all: $(TARGETS)

generate: Makefile board.o cellular_terrain.o generate.cpp
	 $(CXX) $(CXXFLAGS) -o generate board.o cellular_terrain.o generate.cpp

draw: Makefile board.o draw.cpp
	 $(CXX) $(CXXFLAGS) -o draw board.o draw.cpp

random: Makefile board.o cellular_terrain.o random.cpp
	$(CXX) $(CXXFLAGS) -o random board.o cellular_terrain.o random.cpp

facade_test: Makefile board.o cellular_terrain.o facade_test.cpp
	$(CXX) $(CXXFLAGS) -o facade_test board.o cellular_terrain.o facade_test.cpp

randomize: Makefile board.o cellular_terrain.o randomize.cpp
	$(CXX) $(CXXFLAGS) -o randomize board.o cellular_terrain.o randomize.cpp

clean:
	rm -f *.o

distclean: clean
	rm -f $(TARGETS)

real: distclean all
