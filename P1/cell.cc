#include "cell.h"

Cell::Cell() {}

Cell::Cell(Position position) {
  pos_ = position; 
}

Cell::~Cell() {}

Position Cell::Get_Position_Cell() {
  return pos_; 
}

void Cell::Set_Position_Cell(Position new_position) {
  pos_ = new_position; 
  return; 
}

void Cell::Change_State(States new_state) {
  assert(new_state >= 0 && new_state < 5); 
  state_ = new_state; 
  return; 
}

States Cell::Get_State() {
  return state_; 
}

bool Cell::Is_Used() {
  return used_; 
}

void Cell::Activate() {
  used_ = true; 
}

void Cell::Desactivate() {
  used_ = false; 
}

char Cell::Print_Cell() {
  if (Is_Used()) {
    return 'A'; 
  } else if (state_ == visited) {
    return 'a';   
  } else if (state_ == empty) {
    return ' '; 
  } else if (state_ == obstacule) {
    return '#'; 
  } else if (state_ == wall) {
    return '+'; 
  } 

  return 'E'; 
}

Cell& Cell::operator= (const Cell& cell) {
  this->pos_ = cell.pos_; 
  this->state_ = cell.state_; 
  return *this; 
}
