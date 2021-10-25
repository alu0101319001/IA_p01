CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

all: main

main: main.o simulation_node.o world.o node.o cell.o direction.o position.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

position.o: position.cc position.h
	$(CXX) -c position.cc

direction.o: direction.cc direction.h position.h
	$(CXX) -c direction.cc

cell.o: cell.cc cell.h position.h
	$(CXX) -c cell.cc

node.o: node.cc node.h cell.h position.h
	$(CXX) -c node.cc	

world.o: world.cc world.h node.h cell.h direction.h position.h
	$(CXX) -c world.cc

simulation_node.o: simulation_node.cc simulation_node.h world.h node.h cell.h direction.h position.h
	$(CXX) -c simulation_node.cc	

main.o: main.cc simulation_node.h world.h cell.h direction.h position.h
	$(CXX) -c main.cc

clean:
	del main.exe *.o
