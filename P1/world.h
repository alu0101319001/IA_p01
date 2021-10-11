#ifndef _WORLD_H
#define _WORLD_H

#include "cell.h"

typedef std::vector<std::vector<Cell>> matrix_cell; 

class World {
  public:
    World(); 
    World(const int rows, const int colums); 
    void Create_Board(); 

    Cell Get_Cell(Position pos); 

    void Obstacule_Random(int porcentage); 

    bool Are_Obstacules(Position position); 
    bool Are_Visited(Position position); 

    void Print_World(Position object); 
    void Counter_Obstacules(); 
    void Clear(); 

    World& operator= (const World& world); 

  private: 
    int rows_; 
    int columns_; 
    matrix_cell board_; 
}; 

#endif 

