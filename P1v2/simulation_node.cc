#include "simulation_node.h"

// Constructor - Destructor 
SimNode::SimNode(int rows, int columns, Position start, Position end) {
  int id_start = 0; 
  int id_end = 1; 
  world_ = new World(rows,columns); 
  start_ = new Node(id_start, start);
  start_->Set_Parent(start_);  
  end_ = new Node(id_end, end);  
}
SimNode::~SimNode() {
  delete world_;
  delete start_; 
  delete end_; 
  open_.clear(); 
  close_.clear();  
}

// Función Principal 
void SimNode::Play() {
  Edit_Terminal(); 
  Generate_Obstacule();
  Choose_Function(); 
  Initiate(); 
  Astar(Lower_Cost());
  world_->Print_World(start_->Get_Position(), end_->Get_Position());
  t1 = clock(); 
  Time();  
  system("pause"); 
  return; 
}

// Métodos Principales 
void SimNode::Edit_Terminal() {
  system("COLOR F"); 
  system("MODE 1000,1000");
  system("cls");  
  return; 
}
void SimNode::Generate_Obstacule() {
  bool obstacule;
  int porcentage = 30; 
  std::string file_name;  
  
  std::cout << "Obstaculos --> (0): Manual | (1): Aleatorio -->"; 
  std::cin >> obstacule; 
  if (obstacule) {
    std::cout << "Porcentaje : "; 
    std::cin >> porcentage;
    world_->Obstacule_Random(porcentage);  
  } else {
    std::cout << "Nombre/Ubicacion del fichero: "; 
    std::cin >> file_name; 
    world_->Obstacule_Manual(file_name); 
  }
  return; 
}
void SimNode::Choose_Function() {
  std::cout << "Elegir Funcion Heuristica --> (0): Rectilinea  | (1): Euclidea -->"; 
  std::cin >> ch_func_;
  return; 
}
void SimNode::Initiate() {
  t0 = clock(); 
  Evaluate(start_);
  open_.push_back(start_); 
}

void SimNode::Astar(Node* current_node) {
  if (Is_End(current_node)) {
    Resolve(current_node);
    return;   
  } else {
    Add(close_ , current_node); 
    Generate_Children(current_node); 
    Remove(open_ , current_node); 
    if (Empty_List(open_)) {
      std::cout << "\nRESULTADO --> No se ha encontrado un camino posible\n\n"; 
      return; 
    } else {
      Astar(Lower_Cost());   
    }
  }
  return; 
}

void SimNode::Resolve(Node* node) {
  if (node == start_) {
    world_->Get_Cell(node->Get_Position()).Activate(); 
    return; 
  } else {
    world_->Get_Cell(node->Get_Position()).Activate(); 
    Resolve(node->Get_Parent()); 
  }
  return; 
}

void SimNode::Time() {
  double time = (double (t1-t0)/CLOCKS_PER_SEC); 
  std::cout << "\nEXECUTION TIME: " << time << std::endl; 
  return; 
}

// Métodos Secundarios 
Node* SimNode::Lower_Cost() {
  float min = 999999;
  Node* aux; 
  Node* result;   
  for (auto it = open_.begin(); it != open_.end(); ++it) {
    aux = *it; 
    if (aux->Get_Cost() < min) {
      min = aux->Get_Cost();
      result = *it;  
    }
  }
  return result; 
}
void SimNode::Evaluate(Node * node) {
  int rute; 
  float heuristic, result; 
  rute = Rute_Cost(node);
  if (ch_func_) {
    heuristic = Euclidean(node); 
  } else {
    heuristic = Rectilinear(node); 
  }
  result = rute + heuristic;
  node->Set_Cost(result); 
}
void SimNode::Generate_Children(Node* node) {
  Node* child; 
  Position move; 
  // Moverse Arriba
  move = node->Get_Position().Go_Up(); 
  if (Is_Possible(move)) {
    child = new Node(counter_id_ , move); 
    counter_id_ += 1; 
    child->Set_Parent(node); 
    node->Add_Child(child); 
    Evaluate(child); 
    Add(open_ , child); 
  }
  // Moverse Derecha
  move = node->Get_Position().Go_Right(); 
  if (Is_Possible(move)) {
    child = new Node(counter_id_ , move); 
    counter_id_ += 1; 
    child->Set_Parent(node); 
    node->Add_Child(child); 
    Evaluate(child); 
    Add(open_ , child); 
  }
  // Moverse Abajo
  move = node->Get_Position().Go_Down(); 
  if (Is_Possible(move)) {
    child = new Node(counter_id_ , move); 
    counter_id_ += 1; 
    child->Set_Parent(node); 
    node->Add_Child(child); 
    Evaluate(child); 
    Add(open_ , child); 
  }
  // Moverse Izquierda
  move = node->Get_Position().Go_Left(); 
  if (Is_Possible(move)) {
    child = new Node(counter_id_ , move); 
    counter_id_ += 1; 
    child->Set_Parent(node); 
    node->Add_Child(child); 
    Evaluate(child); 
    Add(open_ , child); 
  }
}
bool SimNode::Is_End(Node* node) {
  if (end_->Get_Position() == node->Get_Position()) {
    return true; 
  } 
  return false; 
}

// Funciones para Evaluate 
int SimNode::Rute_Cost(Node* node) {
  if (node == start_) {
    int cost = 0; 
    return cost; 
  } else {
    int recursive_cost; 
    recursive_cost = Rute_Cost(node->Get_Parent()); 
    recursive_cost += 1; 
    return recursive_cost; 
  }
}
int SimNode::Rectilinear(Node* node) {
  int result, x, y; 
  x = std::abs(end_->Get_Position().Get_x() - node->Get_Position().Get_x()); 
  y = std::abs(end_->Get_Position().Get_y() - node->Get_Position().Get_y()); 
  result = x + y; 
  return result; 
}
float SimNode::Euclidean(Node* node) {
  float result; 
  int x, y; 
  x = pow((end_->Get_Position().Get_x() - node->Get_Position().Get_x()) , 2); 
  y = pow((end_->Get_Position().Get_y() - node->Get_Position().Get_y()) , 2);
  result = sqrt(x+y); 
  return result;   
}

// Funciones para Generate Children
bool SimNode::Is_Possible(Position pos) {
  if ((world_->Is_Possible(pos)) && (!Exist(close_ , pos))) {
    return true; 
  }
  return false; 
}

// Métodos Soporte 
void SimNode::Remove(std::list<Node*>& list, Node* node) {
  Node* aux; 
  for (auto it = list.begin(); it != list.end(); ++it) {
    aux = *it; 
    if (aux->Get_ID() == node->Get_ID()) {
      list.erase(it);
      return;  
    }
  }
}
void SimNode::Add(std::list<Node*>& list, Node* node) {
  list.push_front(node); 
  return; 
}
bool SimNode::Exist(const std::list<Node*>& list, Node* node) {
  Node* aux; 
  for (auto it = list.begin(); it != list.end(); ++it) {
    aux = *it; 
    if (aux->Get_ID() == node->Get_ID()) {
      return true; 
    }
  }
  return false; 
} 
bool SimNode::Exist(const std::list<Node*>& list, Position pos) {
  Node* aux; 
  for (auto it = list.begin(); it != list.end(); ++it) {
    aux = *it; 
    if (aux->Get_Position() == pos) {
      return true; 
    }
  }
  return false; 
}
bool SimNode::Empty_List(const std::list<Node*>& list) {
  if (list.empty()) {
    return true; 
  }
  return false; 
}
void SimNode::Print_List(const std::list<Node*>& list) {
  int element = 1; 
  Node* aux; 
  for (auto it = list.begin(); it != list.end(); ++it) {
    aux = *it; 
    std::cout << "\tElemento " << element << ": " << aux->Get_ID(); 
    aux->Get_CellRelation()->Print_Pos(); 
    aux->Get_Parent()->Get_CellRelation()->Print_Pos();
    std::cout << aux->Get_Cost() << std::endl; 
    element += 1;  
  }
  return; 
}



