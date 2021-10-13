#include "simulation.h"

Simulation::Simulation(Car& car, World& world) {
  car_ = car; 
  world_ = world; 
}

Simulation::~Simulation() {}

void Simulation::Play(int porcentage, int max_time) {
  bool obstacule;
  std::string file_name;  
  
  std::cout << "Obstaculos --> Manual (0) - Aleatorio(1) : "; 
  std::cin >> obstacule; 
  if (obstacule) {
    std::cout << "Porcentaje : "; 
    std::cin >> porcentage;
    world_.Obstacule_Random(porcentage);  
  } else {
    std::cout << "Nombre/Ubicacion del fichero: "; 
    std::cin >> file_name; 
    world_.Obstacule_Manual(file_name); 
  }
  
  /*
  for (unsigned int timer = 0; timer <= max_time; timer++)
  {
    world_.Clear(); 
    std::cout << "TIME: " << timer << "\n"; 
    world_.Print_World(car_.Get_Position());
    //world_.Counter_Obstacules();  
    Rute(); 
    system("pause"); 
  }
  */

  world_.Clear(); 
  std::cout << "SIMULATION" << "\n"; 
  world_.Print_World(car_.Get_Position());
  world_.Counter_Obstacules();  
  Rute(); 
  system("pause");

  return; 
}


void Simulation::Rute() {
  Position next_car; 
  int counter = 0;
  next_car = car_.Next_Position(); 
  
  while(((world_.Are_Obstacules(next_car)) || (world_.Are_Visited(next_car))) && (counter != 8)) {
   car_.Turn_Right(); 
   next_car = car_.Next_Position(); 
   counter++; 
  }

  if (counter == 8) {
    std::cout << "Imposible Route" << std::endl; 
  } else if (world_.Get_Cell(next_car).Get_State() == wall) {
    std::cout << "World limit reached: response protocol not configured." << std::endl; 
    std::cout << "Answer: hold position." << std::endl; 
  } else {
   car_.Move();            
  }
  return; 
}