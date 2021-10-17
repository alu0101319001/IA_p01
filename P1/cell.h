// Definición de la clase celda 
#ifndef _CELL_H
#define _CELL_H

#include "position.h"

enum States {empty, obstacule, wall_v, wall_h, wall_eno, wall_ene, wall_ese, wall_eso, visited}; 

class Cell {
  public:
    Cell(); 
    Cell(Position position); 
    ~Cell(); 

    Position Get_Position_Cell(); 

    void Set_Position_Cell(Position new_position); 
    void Change_State(States new_state);
    States Get_State();  
    bool Is_Used(); 

    void Activate(); 
    void Desactivate(); 

    char Print_Cell(); 

    Cell& operator= (const Cell& cell); 

  private: 
    Position pos_; 
    States state_ = empty; 
    bool used_ = false; 
}; 

#endif 

