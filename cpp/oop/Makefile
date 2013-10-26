CXX=g++
CXXFLAGS=-Wall -c

all: rect

rect: rectangle.o main.o
	$(CXX) rectangle.o main.o -o rect

rectangle.o: rectangle.cpp rectangle.h
	$(CXX) $(CXXFLAGS) rectangle.cpp

main.o: main.cpp rectangle.h
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm -rf *.o rect
