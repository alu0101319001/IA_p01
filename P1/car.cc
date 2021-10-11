#include "car.h"

Car::Car() {
  sensor_.Set_facing(UP); 
}

Car::Car(Position start) {
  pos_car_ = start; 
  sensor_.Set_facing(UP); 
}

Car::~Car() {}

void Car::Pos_Car(const int x, const int y) {
  pos_car_.Set_x(x); 
  pos_car_.Set_y(y); 
  return; 
}

int Car::Get_pos_x() {
  return pos_car_.Get_x(); 
}

int Car::Get_pos_y() {
  return pos_car_.Get_y(); 
}

Position Car::Get_Position() {
  return pos_car_; 
}

void Car::Set_pos_x(const int x) {
  pos_car_.Set_x(x); 
  return; 
}

void Car::Set_pos_y(const int y) {
  pos_car_.Set_y(y); 
  return; 
}

void Car::Look_to(Looking arrow) {
  sensor_.Set_facing(arrow); 
  return; 
}

void Car::Turn_Right() {
  sensor_.Turn(RIGHT); 
  return; 
}

void Car::Turn_Left() {
  sensor_.Turn(LEFT); 
  return; 
}

void Car::Move() {
  Position next = Next_Position(); 
  pos_car_.Set_Position(next.Get_x(), next.Get_y()); 
  return; 
}

Position Car::Next_Position() {
  Position next(pos_car_.Get_x(), pos_car_.Get_y()); 

  if (sensor_.Get_facing() == UP) {
    next.Set_Position(pos_car_.Get_x() - 1, pos_car_.Get_y()); 
    return next;
  } else if (sensor_.Get_facing() == DOWN) {
    next.Set_Position(pos_car_.Get_x() + 1, pos_car_.Get_y()); 
    return next; 
  } else if (sensor_.Get_facing() == RIGHT) {
    next.Set_Position(pos_car_.Get_x(), pos_car_.Get_y() + 1); 
    return next; 
  } else if (sensor_.Get_facing() == LEFT) {
    next.Set_Position(pos_car_.Get_x(), pos_car_.Get_y() - 1); 
    return next; 
  } else {}

  return next; 
}

void Car::Go_up() {
  pos_car_.Set_Position(pos_car_.Get_x() - 1, pos_car_.Get_y()); 
  return; 
}

void Car::Go_down() {
  pos_car_.Set_Position(pos_car_.Get_x() + 1, pos_car_.Get_y()); 
  return;
}

void Car::Go_right() {
  pos_car_.Set_Position(pos_car_.Get_x(), pos_car_.Get_y() + 1); 
  return; 
}

void Car::Go_left() {
  pos_car_.Set_Position(pos_car_.Get_x(), pos_car_.Get_y() - 1); 
  return;
}

Car& Car::operator= (const Car& car) {
  this->pos_car_ = car.pos_car_;
  this->sensor_ = car.sensor_; 
  return *this; 
}
