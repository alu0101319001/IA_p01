#include "position.h"

Position::Position(const int x, const int y) {
  x_ = x; 
  y_ = y; 
}

Position::~Position() {}

int Position::Get_x() const {
  return x_; 
}

int Position::Get_y() const {
  return y_; 
}

void Position::Set_x(const int new_x) {
  assert(new_x >= 0); 
  x_ = new_x; 
  return; 
}

void Position::Set_y(const int new_y) {
  assert(new_y >= 0); 
  y_ = new_y; 
  return; 
}

void Position::Set_Position(const int new_x, const int new_y) {
  assert(new_x >= 0 && new_y >= 0); 
  x_ = new_x; 
  y_ = new_y; 
  return; 
}

Position Position::Go_Up() {
  Position result; 
  result.Set_Position(x_ - 1, y_); 
  return result; 
}

Position Position::Go_Down() {
  Position result; 
  result.Set_Position(x_ + 1, y_); 
  return result; 
}

Position Position::Go_Left() {
  Position result; 
  result.Set_Position(x_, y_ - 1); 
  return result; 
}

Position Position::Go_Right() {
  Position result; 
  result.Set_Position(x_, y_ + 1); 
  return result; 
}

Position& Position::operator= (const Position& position) {
  this->x_ = position.x_; 
  this->y_ = position.y_; 
  return *this; 
}

bool Position::operator== (const Position& position) const {
  return this->x_ == position.x_ && this->y_ == position.y_; 
}