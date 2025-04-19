CXX = g++
CXXFLAGS = -Wall

cpp: matrix.hpp matrix.cpp
	$(CXX) $(CXXFLAGS) matrix.cpp -o cpp 

c: matrix.h matrix.c
	$(CXX) $(CXXFLAGS) matrix.c -o c

runcpp:
	./cpp

runc:
	./c