#ifndef _CAR_H
#define _CAR_H

#include "direction.h"

class Car {
  public: 
    Car();
    Car(Position start);  
    ~Car(); 

    void Pos_Car(const int x, const int y); 
    int Get_pos_x(); 
    int Get_pos_y(); 
    Position Get_Position(); 

    void Set_pos_x(const int x); 
    void Set_pos_y(const int y); 

    void Look_to(Looking arrow); 
    void Turn_Right(); 
    void Turn_Left(); 
    void Move(); 
    Position Next_Position(); 

    Car& operator= (const Car& car); 

  private: 
    Position pos_car_; 
    Direction sensor_; 

    void Go_up(); 
    void Go_down(); 
    void Go_right(); 
    void Go_left(); 
}; 

#endif