#include "direction.h"

Direction::Direction() {
  facing_ = UP; 
}

Direction::Direction(Looking facing) {
  facing_ = facing; 
}

Direction::~Direction() {}

char Direction::Get_facing() {
  return facing_; 
}

void Direction::Set_facing(Looking direction) {
  facing_ = direction; 
}

void Direction::Turn(Looking direction) {
  switch (facing_)
  {
  case UP:
    if (direction == RIGHT)
      facing_ = RIGHT; 
    if (direction == LEFT)
      facing_ = LEFT; 
    break;
  
  case LEFT:
    if (direction == LEFT)
      facing_ = DOWN; 
    if (direction == RIGHT)
      facing_ = UP; 
    break; 
  
  case DOWN:
    if (direction == RIGHT)
      facing_ = LEFT; 
    if (direction == LEFT)
      facing_ = RIGHT; 
    break; 
  
  case RIGHT:
    if (direction == RIGHT)
      facing_ = DOWN; 
    if (direction == LEFT)
      facing_ = UP; 
    break; 
    
  default:
    break;
  }

}

void Direction::Back() {
  switch(facing_)
  {
    case UP:
      facing_ = DOWN; 
      break; 
    
    case DOWN:
      facing_ = UP; 
      break; 

    case LEFT:
      facing_ = RIGHT; 
      break; 

    case RIGHT:
      facing_ = LEFT; 
      break; 
    
    default:
      break; 
  }
}

Direction& Direction::operator= (const Direction& dir) {
  this->facing_ = dir.facing_; 
  return *this; 
}
