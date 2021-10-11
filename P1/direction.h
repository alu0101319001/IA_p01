#ifndef _DIRECTION_H
#define _DIRECTION_H

#include "position.h"

enum Looking :char {UP='^',LEFT='<', DOWN='v', RIGHT='>'}; 

class Direction {
  public:
    Direction(); 
    Direction(Looking facing); 
    ~Direction(); 

    char Get_facing();
    void Set_facing(Looking direction); 
    void Turn(Looking direction);  
    void Back(); 

    Direction& operator= (const Direction& dir); 

  private:
    Looking facing_; 

}; 

#endif