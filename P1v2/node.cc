#include "node.h"

Node::Node() {
  id_ = -1; 
  cost_ = -1; 
  parent_ = nullptr; 
  relation_cell_ = nullptr; 
}
Node::Node(int id, Position pos) {
  id_ = id; 
  cost_ = -1; 
  parent_ = nullptr;
  relation_cell_ = new Cell(pos);  
}
Node::~Node() {
  children_.clear();
  delete parent_; 
  delete relation_cell_;  
}

// Getters
int Node::Get_ID() {
  return id_; 
}
double Node::Get_Cost() {
  return cost_; 
}
Node* Node::Get_Parent() {
  return parent_; 
}
std::list<Node*> Node::Get_ChildrenList() {
  return children_; 
}
Cell* Node::Get_CellRelation() {
  return relation_cell_; 
}
Position Node::Get_Position() {
  return relation_cell_->Get_Position_Cell(); 
}

//Setters
void Node::Set_ID(int id) {
  id_ = id; 
}
void Node::Set_Cost(double cost) {
  cost_ = cost; 
}
void Node::Set_Parent(Node* parent) {
  parent_ = parent; 
}
void Node::Add_Child(Node* child) {
  children_.push_back(child); 
}
void Node::Set_Cell(Cell* cell) {
  relation_cell_ = cell; 
}

// Sobrecarga operadores 
Node& Node::operator= (const Node& node) {
  this->id_ = node.id_; 
  this->cost_ = node.cost_; 
  this->parent_ = node.parent_; 
  this->children_ = node.children_; 
  this->relation_cell_ = node.relation_cell_; 
  return *this; 
}

bool Node::operator== (const Node& node) const {
  return this->id_ == node.id_; 
}