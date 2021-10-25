#ifndef _WORLD_H
#define _WORLD_H

#include "cell.h"

typedef std::vector<std::vector<Cell>> matrix_cell; 

class World {
  public:
    World(); 
    World(const int rows, const int colums); 
    void Create_Board(); 

    Cell& Get_Cell(Position pos); 

    void Obstacule_Random(int porcentage);
    void Obstacule_Manual(std::string file_name);  

    bool Are_Obstacules(Position position);  
    bool Is_Possible(Position pos); 

    void Print_World(Position start, Position end); 
    void Counter_Obstacules(); 
    void Clear(); 

    World& operator= (const World& world); 

  private: 
    int rows_; 
    int columns_; 
    int obstacules_; 
    matrix_cell board_; 
}; 

#endif 

