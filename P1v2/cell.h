// Definición de la clase celda 
#ifndef _CELL_H
#define _CELL_H

#include "position.h"

enum States {empty, obstacule, wall_v, wall_h, wall_eno, wall_ene, wall_ese, wall_eso, start_c, end_c, eval}; 

class Cell {
  public:
    Cell(); 
    Cell(Position position); 
    ~Cell(); 

    void Set_Position_Cell(Position new_position);
    void Set_Position_Cell(int x, int y);
    void Change_State(States new_state);

    Position Get_Position_Cell(); 
    States Get_State();  

    bool Is_Used(); 
    void Activate(); 
    void Desactivate(); 

    char Print_Cell();
    void Print_Pos();  

    Cell& operator= (const Cell& cell); 

  private: 
    Position pos_; 
    States state_ = empty; 
    bool used_ = false;
}; 

#endif 

