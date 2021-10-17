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
  assert(new_state >= 0 && new_state < 9); 
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
    char ob = 169; 
    return ob; 
  } else if (state_ == visited) {
    return 'x';   
  } else if (state_ == empty) {
    return ' '; 
  } else if (state_ == obstacule) {
    char ob = 219; 
    return ob; 
  } else if (state_ == wall_v) {
    char ob = 186; 
    return ob; 
  } else if (state_ == wall_h) {
    char ob = 205;
    return ob; 
  } else if (state_ == wall_ene) {
    char ob = 187;
    return ob; 
  } else if (state_ == wall_ese) {
    char ob = 188;
    return ob; 
  } else if (state_ == wall_eno) {
    char ob = 201;
    return ob; 
  } else if (state_ == wall_eso) {
    char ob = 200;
    return ob; 
  } 

  return 'E'; 
}

Cell& Cell::operator= (const Cell& cell) {
  this->pos_ = cell.pos_; 
  this->state_ = cell.state_; 
  return *this; 
}
