#include "simulation.h"

Simulation::Simulation(World& world, Position start, Position end) {
  world_ = world;

  start_ = start; 
  end_ = end;  
}

Simulation::~Simulation() {}

void Simulation::Play() {
  Edit_Terminal();  
  Generate_Obstacule();
  std::cout << "SIMULATION" << "\n"; 
  world_.Print_World(start_, end_);  
  Initate(); 
  Astar(Lower_Cost());     
  std::cout << "SIMULATION" << "\n"; 
  world_.Print_World(start_, end_);
  //world_.Counter_Obstacules();  
  system("pause");

  return; 
}

void Simulation::Test() {
  Edit_Terminal(); 
  Generate_Obstacule();
  Initate();
  std::cout << "Evaluated_Cost de Inicial: " << world_.Get_Cell(start_).Get_Cost() << std::endl; 
  Print_List(open_list_);
  std::cout << "Lower Cost: " << Lower_Cost().Get_Id() << std::endl; 
  Generate_Children(Lower_Cost().Get_Position_Cell()); 
  Print_List(world_.Get_Cell(start_).Get_Children());
  Evaluate_Children(world_.Get_Cell(start_)); 
  Eliminate_to_OpenList(world_.Get_Cell(start_)); 
  close_list_.push_back(world_.Get_Cell(start_)); 
  Add_Children_to_OpenList(world_.Get_Cell(start_));
  std::cout << "Open List:\n";  
  Print_List(open_list_);
  std::cout << "Close List:\n";  
  Print_List(close_list_); 
  std::cout << "Lower Cost: " << Lower_Cost().Get_Id() << std::endl;
  std::cout << "SIMULATION" << "\n"; 
  world_.Print_World(start_, end_); 
  system("pause"); 
  return; 
}

bool Simulation::Exist_CloseList(Cell cell) {
  for (auto it = close_list_.begin(); it != close_list_.end(); it++) {
    if (it->Get_Id() == cell.Get_Id()) {
      return true; 
    }
  }
  return false; 
}

void Simulation::Eliminate_to_OpenList(Cell& node) {
  for (auto it = open_list_.begin(); it != open_list_.end(); it++) {
    if (it->Get_Id() == node.Get_Id()) {
      open_list_.erase(it); 
      return; 
    }
  }
}

void Simulation::Print_List(std::list<Cell>& list) {
  int count = 1; 
  for (auto it = list.begin(); it != list.end(); it++) {
    std::cout << "Elemento " << count << ": " << it->Get_Id(); 
    it->Print_Pos();
    it->Print_Parent();  
    std::cout << it->Get_Cost() << std::endl; 
    count += 1; 
  } 
  return; 
}

bool Simulation::Is_Possible(Position pos) {
  if ((world_.Is_Possible(pos)) && (!Exist_CloseList(world_.Get_Cell(pos)))) {
    return true;     
  }
  return false; 
}

void Simulation::Generate_Obstacule() {
  bool obstacule;
  int porcentage = 30; 
  std::string file_name;  
  
  std::cout << "Obstaculos --> Manual (0) - Aleatorio(1) : "; 
  std::cin >> obstacule; 
  if (obstacule) {
    std::cout << "Porcentaje : "; 
    std::cin >> porcentage;
    world_.Obstacule_Random(porcentage);  
  } else {
    std::cout << "Nombre/Ubicacion del fichero: "; 
    std::cin >> file_name; 
    world_.Obstacule_Manual(file_name); 
  }
  return; 
}

void Simulation::Generate_SpecialNodes() {
  int star_id = 0, end_id = 1; 
  world_.Set_ID(start_, star_id); 
  world_.Set_ID(end_, end_id);
}

void Simulation::Generate_Children(Position origin) {
  if (Is_Possible(origin.Go_Up())) {
    world_.Get_Cell(origin.Go_Up()).Set_ID(counter_id_); 
    counter_id_++; 
    world_.Get_Cell(origin.Go_Up()).Set_Parent(origin); 
    world_.Get_Cell(origin).Add_Children(world_.Get_Cell(origin.Go_Up())); 
  }
   if (Is_Possible(origin.Go_Right())) {
    world_.Get_Cell(origin.Go_Right()).Set_ID(counter_id_); 
    counter_id_++; 
    world_.Get_Cell(origin.Go_Right()).Set_Parent(origin);  
    world_.Get_Cell(origin).Add_Children(world_.Get_Cell(origin.Go_Right())); 
  }
  if (Is_Possible(origin.Go_Down())) {
    world_.Get_Cell(origin.Go_Down()).Set_ID(counter_id_); 
    counter_id_++; 
    world_.Get_Cell(origin.Go_Down()).Set_Parent(origin);  
    world_.Get_Cell(origin).Add_Children(world_.Get_Cell(origin.Go_Down())); 
  }
  if (Is_Possible(origin.Go_Left())) {
    world_.Get_Cell(origin.Go_Left()).Set_ID(counter_id_); 
    counter_id_++; 
    world_.Get_Cell(origin.Go_Left()).Set_Parent(origin);  
    world_.Get_Cell(origin).Add_Children(world_.Get_Cell(origin.Go_Left())); 
  }
  return;    
}

int Simulation::Rute_Cost(Position pos) {
  if (world_.Get_Cell(pos).Get_Id() == 0) {
    int cost;   
    cost = 0; 
    return cost;     
  } else {
    int return_cost; 
    return_cost = Rute_Cost(world_.Get_Cell(pos).Get_Parent()); 
    return_cost += 1; 
    return return_cost; 
  }
}

int Simulation::Rectilinear_Distance(Position pos) {
  int result; 
  int x, y; 
  x = std::abs(end_.Get_x() - pos.Get_x());  
  y = std::abs(end_.Get_y() - pos.Get_y());  
  result = x + y;  
  return result; 
}

float Simulation::Euclidean_Distance(Position pos) {
  float result; 
  int x, y; 
  x = pow((end_.Get_x() - pos.Get_x()) , 2); 
  y = pow((end_.Get_y() - pos.Get_y()) , 2); 
  result = sqrt(x+y); 
  return result; 
}

void Simulation::Evaluate(Position node) {
  int rect, rute; 
  rute = Rute_Cost(node); 
  rect = Rectilinear_Distance(node);  
  world_.Get_Cell(node).Set_EvaluateCost(rute + rect); 
  return;   
}

void Simulation::Evaluate_Children(Cell& parent_node) {
  for (auto it = parent_node.Get_Children().begin(); 
  it != parent_node.Get_Children().end(); it++ ) 
  {
    Evaluate(it->Get_Position_Cell()); 
  }
  return; 
}

void Simulation::Add_Children_to_OpenList(Cell& parent_node) {
  for (auto it = parent_node.Get_Children().begin();
  it != parent_node.Get_Children().end(); it++) 
  {
    open_list_.push_back(world_.Get_Cell(it->Get_Position_Cell())); 
  }
  return; 
}

Cell& Simulation::Lower_Cost() {
  float min = INFINITY; 
  Position aux_pos; 
  for (auto it = open_list_.begin(); it != open_list_.end(); it++) {
    if (it->Get_Cost() < min) {
      min = it->Get_Cost(); 
      aux_pos = it->Get_Position_Cell(); 
    }
  }
  return world_.Get_Cell(aux_pos); 
}

void Simulation::Initate() {
  Generate_SpecialNodes(); 
  Evaluate(start_);  
  open_list_.push_back(world_.Get_Cell(start_)); 
  return; 
}

void Simulation::Astar(Cell& current_node) {
  std::cout << "Astar ID: " << current_node.Get_Id() << std::endl; 
  if (current_node.Get_Id() == 1) {
    Resolve(current_node); 
    return; 
  } else {
    //Generar nodos hijos
    //std::cout << "Genero hijos" << std::endl;
    Generate_Children(current_node.Get_Position_Cell()); 
    //Evaluar nodos hijos
    //std::cout << "Evaluo hijos" << std::endl;
    Evaluate_Children(current_node); 
    //Eliminar de lista abierta
    //std::cout << "Elimino de lista abierta" << std::endl;
    Eliminate_to_OpenList(current_node); 
    //Añadir a lista cerrada
    //std::cout << "Añado a lsita cerrada" << std::endl;
    close_list_.push_back(current_node); 
    //Añadir hijos a lista abierta
    //std::cout << "Añado a lista abierta" << std::endl;
    Add_Children_to_OpenList(current_node);
    std::cout << "Open List" << std::endl; 
    Print_List(open_list_); 
    std::cout << "Close List" << std::endl; 
    Print_List(close_list_); 
    system("pause");  
    Astar(Lower_Cost());
    return;  
  } 
}

void Simulation::Resolve(Cell& node) {
  if (node.Get_Id() == 0) {
    world_.Get_Cell(node.Get_Position_Cell()).Activate();
    return;  
  } else {
    world_.Get_Cell(node.Get_Position_Cell()).Activate();
    Resolve(world_.Get_Cell(node.Get_Position_Cell()));
    return;  
  }
} 

void Simulation::Edit_Terminal() {
  system("COLOR F"); 
  system("MODE 1000,1000");
  system("cls");  
  return; 
}

