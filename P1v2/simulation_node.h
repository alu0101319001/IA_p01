#ifndef _SIM_NODE_H
#define _SIM_NODE_H

#include "world.h"
#include "node.h"

class SimNode{
  public:
    SimNode(int rows, int columns, Position start, Position end); 
    ~SimNode(); 

    void Play();  

  private:
    // ATRIBUTOS 
    World* world_; 
    Node* start_; 
    Node* end_; 
    std::list<Node*> open_; 
    std::list<Node*> close_; 
    int counter_id_ = 2;
    bool ch_func_; 
    unsigned t0,t1; 

    // MÉTODOS PRINCIPALES
    void Edit_Terminal(); 
    void Generate_Obstacule();
    void Choose_Function();  
    void Initiate(); 
    void Astar(Node* node);
    void Resolve(Node* node); 
    void Time(); 

    // MÉTODOS SECUNDARIOS 
    Node* Lower_Cost(); 
    void Evaluate(Node* node); 
    void Generate_Children(Node* node);
    bool Is_End(Node* node); 

    // FUNCIONES PARA EVALUATE
    int Rute_Cost(Node* node); 
    int Rectilinear(Node* node); 
    float Euclidean(Node* node);

    // FUNCIONES PARA GENERATE CHILDREN
    bool Is_Possible(Position pos);  

    // MÉTODOS SOPORTE 
    void Remove(std::list<Node*>& list , Node* node);
    void Add(std::list<Node*>& list, Node* node);
    bool Exist(const std::list<Node*>& list, Node* node); 
    bool Exist(const std::list<Node*>& list, Position pos);
    bool Empty_List(const std::list<Node*>& list); 
    void Print_List(const std::list<Node*>& list);  



}; 

#endif