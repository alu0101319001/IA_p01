#include "simulation.h"

void Rute(Car& taxi, World& world); 

int main() {
  int filas = 20, columnas = 40; 
  unsigned int max_time = 100; 
  int porcentage = 30;
  Position start(10,20); 
  Car taxi(start); 
  World world(filas,columnas); 

  
  world.Obstacule_Random(porcentage); 
    for (unsigned int timer = 0; timer <= max_time; timer++)
    {
       world.Clear(); 
       std::cout << "TIME: " << timer << "\n"; 
       world.Print_World(taxi.Get_Position()); 
       Rute(taxi, world);
       system("pause"); 
    }
    return 0; 
}

void Rute(Car& taxi, World& world) {
  Position next_taxi; 
  int counter = 0;
  next_taxi = taxi.Next_Position(); 
  
  while((world.Are_Obstacules(next_taxi)) && (counter != 8)) {
    taxi.Turn_Right(); 
    next_taxi = taxi.Next_Position(); 
    counter++; 
  }

  if (counter == 8) {
    std::cout << "Imposible Route" << std::endl; 
  } else if (world.Get_Cell(next_taxi).Get_State() == wall) {
    std::cout << "World limit reached: response protocol not configured." << std::endl; 
    std::cout << "Answer: hold position." << std::endl; 
  } else {
    taxi.Move();            
  }
  return; 
}