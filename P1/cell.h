// Definición de la clase celda 
#ifndef _CELL_H
#define _CELL_H

#include "position.h"

enum States {empty, obstacule, wall_v, wall_h, wall_eno, wall_ene, wall_ese, wall_eso, start_c, end_c}; 

class Cell {
  public:
    Cell(); 
    Cell(Position position); 
    ~Cell(); 

    void Set_Position_Cell(Position new_position);
    void Set_Position_Cell(int x, int y);
    void Set_ID(int id); 
    void Set_EvaluateCost(float cost);  
    void Add_Children(Cell child);
    void Set_Parent(Position parent);  
    void Change_State(States new_state);

    Position Get_Position_Cell(); 
    States Get_State();
    int Get_Id();
    Position Get_Parent();
    std::list<Cell>& Get_Children();   
    float Get_Cost();   

    bool Is_Used(); 
    void Activate(); 
    void Desactivate(); 

    char Print_Cell();
    void Print_Pos();
    void Print_Parent();   

    Cell& operator= (const Cell& cell); 

  private: 
    Position pos_; 
    States state_ = empty; 
    bool used_ = false;
    int id_ = -1;
    float evaluated_cost_;  
    Position parent_;   
    std::list<Cell> children_list_;   
}; 

#endif 

