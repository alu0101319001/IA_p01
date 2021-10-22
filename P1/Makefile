CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

all: main

main: main.o simulation.o world.o cell.o direction.o position.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

position.o: position.cc position.h
	$(CXX) -c position.cc

direction.o: direction.cc direction.h position.h
	$(CXX) -c direction.cc

cell.o: cell.cc cell.h position.h
	$(CXX) -c cell.cc

world.o: world.cc world.h cell.h direction.h position.h
	$(CXX) -c world.cc

simulation.o: simulation.cc simulation.h world.h cell.h direction.h position.h
	$(CXX) -c simulation.cc	

main.o: main.cc simulation.h world.h cell.h direction.h position.h
	$(CXX) -c main.cc

clean:
	del main.exe *.o
