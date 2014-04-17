CXX=g++
CXXFLAGS=-Wall -c

all: student

student: student.o main.o
	$(CXX) student.o main.o -o student

student.o: student.cpp student.h
	$(CXX) $(CXXFLAGS) student.cpp

main.o: main.cpp student.h
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm -rf *.o student
