#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "world.h"

class Simulation {
  public: 
    Simulation(World& World, Position start, Position end); 
    ~Simulation(); 

    void Play(); 
    void Test(); 

  private: 
    World world_; 
    int counter_id_ = 2;
    Position start_; 
    Position end_;
    std::list<Cell> open_list_; 
    std::list<Cell> close_list_;   

    bool Exist_CloseList(Cell cell);
    void Eliminate_to_OpenList(Cell& node);    
    void Print_List(std::list<Cell>& list);  

    bool Is_Possible(Position pos);

    void Generate_Obstacule();
    void Generate_SpecialNodes();
    void Generate_Children(Position pos);   

    int Rute_Cost(Position pos); 
    int Rectilinear_Distance(Position pos);
    float Euclidean_Distance(Position pos);  
    void Evaluate(Position node);
    void Evaluate_Children(Cell& parent_node);
    void Add_Children_to_OpenList(Cell& parent_node);     

    Cell& Lower_Cost();
    void Initate(); 
    void Astar(Cell& node);  
    void Resolve(Cell& node); 
    void Edit_Terminal(); 
}; 

#endif
