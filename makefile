CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lSDL2 -lSDL2_ttf

# Source files
DEMO_SRCS = Demo.cpp tree_iterators.hpp tree.tpp complex.hpp
TEST_SRCS = test.cpp tree_iterators.hpp tree.tpp complex.hpp

# Object files
OBJS_DEMO = Demo.o
OBJS_TEST = test.o

# Target executables
TARGETS = tree_program test

all: $(TARGETS)

# Rule to build the main demo program
tree_program: $(OBJS_DEMO)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DEMO) $(LDFLAGS)

# Rule to build the test program
test: $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_TEST) $(LDFLAGS)

# Rule to compile each .cpp file to .o
Demo.o: Demo.cpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

# Rule to clean the build
clean:
	rm -f *.o $(TARGETS)

# Rule to build and run the main demo program
tree: tree_program
	./tree_program
