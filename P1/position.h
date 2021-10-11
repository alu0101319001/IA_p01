#ifndef _POSICION_H
#define _POSICION_H

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>

class Position {
  public:
    Position(const int = 0, const int = 0); 
    ~Position(); 

    int Get_x() const; 
    int Get_y() const; 

    void Set_x(const int); 
    void Set_y(const int); 

    void Set_Position(const int x, const int y); 

    Position& operator= (const Position& positon); 
    bool operator== (const Position& position) const; 

  private:
    int x_; 
    int y_; 

}; 

#endif