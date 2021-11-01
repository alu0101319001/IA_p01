#include "simulation_node.h"

// Constructor - Destructor 
SimNode::SimNode() {}
SimNode::SimNode(int rows, int columns, Position start, Position end) {
  int id_start = 0; 
  int id_end = 1; 
  world_ = new World(rows,columns); 
  start_ = new Node(id_start, start);
  start_->Set_Parent(start_);  
  end_ = new Node(id_end, end);  
}
SimNode::~SimNode() {
  //delete start_;  
  delete end_;  
  delete world_;
  close_.clear();  
  open_.clear(); 
  std::cout << "Delete Complete" << std::endl; 
}

void SimNode::Create(int rows, int columns, Position start, Position end) {
  int id_start = 0; 
  int id_end = 1; 
  world_ = new World(rows,columns); 
  start_ = new Node(id_start, start);
  start_->Set_Parent(start_);  
  end_ = new Node(id_end, end);  
}
void SimNode::Eliminate() {
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
  Choose_Direction(); 
  Initiate(); 
  Astar(Lower_Cost());
  world_->Print_World(start_->Get_Position(), end_->Get_Position());
  Table();  
  system("pause"); 
  return; 
}
// Función Principal 
void SimNode::Play_NoObstacule() {
  Edit_Terminal(); 
  Choose_Function(); 
  Choose_Direction(); 
  Initiate(); 
  Astar(Lower_Cost());
  world_->Print_World(start_->Get_Position(), end_->Get_Position());
  Table();  
  system("pause"); 
  return; 
}
void SimNode::Play_Obstacule(int porcentage) {
  Edit_Terminal(); 
  Generate_Obstacule_Define(porcentage); 
  Choose_Function(); 
  Choose_Direction(); 
  Initiate(); 
  Astar(Lower_Cost());
  world_->Print_World(start_->Get_Position(), end_->Get_Position());
  Table();  
  system("pause"); 
  return; 
}

void SimNode::Play_Experimental(bool obstacule, int porcentage, bool function, bool direction) {
  if (obstacule) {
    Generate_Obstacule_Define(porcentage); 
  }
  ch_func_ = function; 
  ch_dir_ = direction; 
  Initiate(); 
  Astar(Lower_Cost()); 
  Table(); 
  return;   
}

// Métodos Principales 
void SimNode::Edit_Terminal() {
  system("COLOR F"); 
  system("MODE 1000,1000");  
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

void SimNode::Generate_Obstacule_Define(int porcentage) {
  world_->Obstacule_Random(porcentage); 
  return; 
}
void SimNode::Choose_Function() {
  std::cout << "Elegir Funcion Heuristica --> (0): Rectilinea  | (1): Euclidea -->"; 
  std::cin >> ch_func_;
  return; 
}
void SimNode::Choose_Direction() {
  std::cout << "Elegir modo de dirección --> (0) 4 Direcciones | (1) 8 direcciones -->"; 
  std::cin >> ch_dir_; 
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
    if ((Empty_List(open_)) || (Time() > 70)) {
      std::cout << "\nRESULTADO --> No se ha encontrado un camino posible\n\n"; 
      return; 
    } else {
      Astar(Lower_Cost());   
    }
  } 
  return; 
}
void SimNode::Astar_Develop(Node* current_node) {
  Node* min; 
  if (Is_End(current_node)) {
    Resolve(current_node);
    return;   
  } else {
    std::cout << "Astar ID: " << current_node->Get_ID() << std::endl; 
    Add(close_ , current_node); 
    Generate_Children(current_node); 
    Remove(open_ , current_node); 
    std::cout << "\tOpen List: \n"; 
    Print_List(open_); 
    std::cout << "\tClose List: \n"; 
    Print_List(close_); 
    system("pause"); 
    if (Empty_List(open_)) {
      std::cout << "\nRESULTADO --> No se ha encontrado un camino posible\n\n"; 
      return; 
    } else {
      std::cout << "Para antes del nuevo Astar" << std::endl;
      min = Lower_Cost();  
      Astar_Develop(min);   
    }
  }
  delete min; 
  return; 
}

void SimNode::Resolve(Node* node) {
  if (node == start_) {
    world_->Get_Cell(node->Get_Position()).Activate(); 
    return; 
  } else {
    world_->Get_Cell(node->Get_Position()).Activate();
    minimal_path_ += 1;  
    Resolve(node->Get_Parent()); 
  }
  return; 
}

double SimNode::Time() {
  t1 = clock(); 
  double time = (double (t1-t0)/CLOCKS_PER_SEC);  
  return time;  
}

void SimNode::Table() {
  std::cout << "RESULTS" << std::endl; 
  std::cout << "\tNodos explorados: " << evaluated_node_ << std::endl; 
  std::cout << "\tLongitud del camino minimo: " << minimal_path_ << std::endl; 
  std::cout << "\tTiempo de ejecucion: " << Time() << std::endl; 
  return; 
}

// Métodos Secundarios 
Node* SimNode::Lower_Cost() {
  double min = INFINITY;
  Node* aux; 
  Node* result; 
  int count = 0, tope = open_.size();    
  for (auto it = open_.begin(); it != open_.end(); ++it) {
    aux = *it; 
    if (aux->Get_Cost() < min) {
      min = aux->Get_Cost();
      result = *it;  
    } else if ((aux->Get_Cost() == min) && (count > tope)) {
      min_ = result; 
      return result;  
    }
    count++; 
  }
  min_ = result; 
  return result; 
}
void SimNode::Evaluate(Node * node) {
  int rute; 
  double heuristic, result; 
  rute = Rute_Cost(node);
  if (ch_func_) {
    heuristic = Euclidean(node); 
  } else {
    heuristic = Rectilinear(node); 
  }
  result = rute + heuristic;
  node->Set_Cost(result); 
  evaluated_node_ += 1; 
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
    if (!Collision(child)) {
      Add(open_ , child); 
    } 
  }
  // Moverse Derecha
  move = node->Get_Position().Go_Right(); 
  if (Is_Possible(move)) {
    child = new Node(counter_id_ , move); 
    counter_id_ += 1; 
    child->Set_Parent(node); 
    node->Add_Child(child); 
    Evaluate(child); 
    if (!Collision(child)) {
      Add(open_ , child);  
    }
  }
  // Moverse Abajo
  move = node->Get_Position().Go_Down(); 
  if (Is_Possible(move)) {
    child = new Node(counter_id_ , move); 
    counter_id_ += 1; 
    child->Set_Parent(node); 
    node->Add_Child(child); 
    Evaluate(child); 
    if (!Collision(child)) {
      Add(open_ , child); 
    } 
  }
  // Moverse Izquierda
  move = node->Get_Position().Go_Left(); 
  if (Is_Possible(move)) {
    child = new Node(counter_id_ , move); 
    counter_id_ += 1; 
    child->Set_Parent(node); 
    node->Add_Child(child); 
    Evaluate(child); 
    if (!Collision(child)) {
      Add(open_ , child); 
    } 
  }

  // Diagonales 
  if (ch_dir_) {
    // Arriba Derecha 
    move = node->Get_Position().Go_DUpRight(); 
    if (Is_Possible(move)) {
      child = new Node(counter_id_, move); 
      counter_id_ += 1; 
      child->Set_Parent(node); 
      node->Add_Child(child); 
      Evaluate(child); 
      if (!Collision(child)) {
      Add(open_ , child); 
      } 
    }
    // Arriba Izquierda
    move = node->Get_Position().Go_DUpLeft(); 
    if (Is_Possible(move)) {
      child = new Node(counter_id_, move); 
      counter_id_ += 1; 
      child->Set_Parent(node); 
      node->Add_Child(child); 
      Evaluate(child); 
      if (!Collision(child)) {
      Add(open_ , child); 
      } 
    }
    // Abajo Derecha 
    move = node->Get_Position().Go_DDownRight(); 
    if (Is_Possible(move)) {
      child = new Node(counter_id_, move); 
      counter_id_ += 1; 
      child->Set_Parent(node); 
      node->Add_Child(child); 
      Evaluate(child); 
      if (!Collision(child)) {
      Add(open_ , child); 
      } 
    }
    // Abajo Izquierda
    move = node->Get_Position().Go_DDownLeft(); 
    if (Is_Possible(move)) {
      child = new Node(counter_id_, move); 
      counter_id_ += 1; 
      child->Set_Parent(node); 
      node->Add_Child(child); 
      Evaluate(child); 
      if (!Collision(child)) {
      Add(open_ , child); 
      } 
    }
  }
}

bool SimNode::Is_End(Node* node) {
  if (end_->Get_Position() == node->Get_Position()) {
    return true; 
  } 
  return false; 
}

bool SimNode::Collision(Node* node) {
  Node* aux; 
  for (auto it = open_.begin(); it != open_.end(); ++it) {
    aux = *it; 
    if ((aux->Get_Position() == node->Get_Position()) && (aux->Get_Parent()->Get_Position() == node->Get_Parent()->Get_Position())) {
      if (aux->Get_Cost() > min_->Get_Cost()) {
        return true; 
      } 
    }
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
double SimNode::Euclidean(Node* node) {
  double result; 
  double x, y;
  x = (end_->Get_Position().Get_x()) - (node->Get_Position().Get_x()); 
  y = (end_->Get_Position().Get_y()) - (node->Get_Position().Get_y()); 
  x = pow(x,2); 
  y = pow(y,2); 
  result = x + y; 
  result = sqrt(result); 
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



