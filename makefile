CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lSDL2 -lSDL2_ttf

# Source files
DEMO_SRCS = Demo.cpp tree_iterators.hpp tree.tpp Complex.hpp
TEST_SRCS = test.cpp tree_iterators.hpp tree.tpp Complex.hpp

# Target executables
TARGETS = tree_program test

all: $(TARGETS)

# Rule to build the main demo program
tree_program: Demo.o
	$(CXX) $(CXXFLAGS) -o $@ Demo.o $(LDFLAGS)

# Rule to build the test program
test: test.o
	$(CXX) $(CXXFLAGS) -o $@ test.o $(LDFLAGS)

# Rule to compile each .cpp file to .o
Demo.o: Demo.cpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

test_tree.o: test_tree.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

# Rule to clean the build
clean:
	rm -f *.o $(TARGETS)
