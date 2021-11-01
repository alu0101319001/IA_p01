#ifndef _SIM_NODE_H
#define _SIM_NODE_H

#include "world.h"
#include "node.h"

class SimNode{
  public:
    SimNode(); 
    SimNode(int rows, int columns, Position start, Position end); 
    ~SimNode(); 

    void Create(int rows, int columns, Position start, Position end); 
    void Eliminate(); 
    void Play();  
    void Play_NoObstacule(); 
    void Play_Obstacule(int porcentage); 
    void Play_Experimental(bool obstacule, int porcentage, bool function, bool direction); 

  private:
    // ATRIBUTOS 
    World* world_; 
    Node* start_; 
    Node* end_;
    Node* min_;  
    std::list<Node*> open_; 
    std::list<Node*> close_; 
    int counter_id_ = 2;
    bool ch_func_;
    bool ch_dir_;  
    unsigned t0,t1; 
    int evaluated_node_ = 0; 
    int minimal_path_ = 0; 
    int max_size_open_ = 100; 

    // MÉTODOS PRINCIPALES
    void Edit_Terminal(); 
    void Generate_Obstacule();
    void Generate_Obstacule_Define(int porcentage); 
    void Choose_Function(); 
    void Choose_Direction();  
    void Initiate(); 
    void Astar(Node* node); 
    void Astar_Develop(Node* node); 
    void Resolve(Node* node); 
    double Time(); 
    void Table(); 

    // MÉTODOS SECUNDARIOS 
    Node* Lower_Cost(); 
    void Evaluate(Node* node); 
    void Generate_Children(Node* node);
    bool Is_End(Node* node); 
    bool Collision(Node* node); 

    // FUNCIONES PARA EVALUATE
    int Rute_Cost(Node* node); 
    int Rectilinear(Node* node); 
    double Euclidean(Node* node);

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