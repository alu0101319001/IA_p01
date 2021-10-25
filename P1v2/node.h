#ifndef _NODE_H
#define _NODE_H

#include "cell.h"

class Node {
  public:
    Node();
    Node(int id, Position pos);  
    ~Node();

    //Getters
    int Get_ID(); 
    float Get_Cost();
    Node* Get_Parent(); 
    std::list<Node*> Get_ChildrenList(); 
    Cell* Get_CellRelation();
    Position Get_Position();    

    //Setters
    void Set_ID(int id); 
    void Set_Cost(float cost); 
    void Set_Parent(Node* parent); 
    void Add_Child(Node* child); 
    void Set_Cell(Cell* cell); 

    // Sobrecarga Operadores 
    Node& operator= (const Node& node); 
    bool operator== (const Node& node) const;       

  private: 
    int id_; 
    float cost_; 
    Node* parent_; 
    std::list<Node*> children_; 
    Cell* relation_cell_; 
}; 

#endif