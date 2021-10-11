#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "car.h"
#include "world.h"

class Simulation {
  public: 
    Simulation(Car& car, World& World); 
    ~Simulation(); 

    void Play(int porcentage, int max_time); 

  private: 
    Car car_; 
    World world_; 

    void Rute(); 
}; 

#endif
