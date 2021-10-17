#include "world.h"

World::World() {}

World::World(const int rows, const int columns) {
  if ((rows > 500) || (columns > 500) || (rows < 0) || (columns < 0)) {
    std::cout << "Error : size not allowed" << std::endl;
    exit(1);  
  } else {
    columns_ = columns + 2; 
    rows_ = rows + 2; 
    obstacules_ = 0; 
    Create_Board(); 
  }
}

void World::Create_Board() {
  board_.resize(rows_); 
  for (int i = 0; i < rows_; i++) {
    board_[i].resize(columns_); 
  }

  // Esquinas
  board_[0][0].Change_State(wall_eno); 
  board_[0][columns_-1].Change_State(wall_ene); 
  board_[rows_ - 1][0].Change_State(wall_eso); 
  board_[rows_ - 1][columns_ - 1].Change_State(wall_ese); 

  for(int i = 1; i < rows_ - 1; i++) {
    board_[i][0].Change_State(wall_v); 
    board_[i][columns_-1].Change_State(wall_v); 
  }
  for (int j = 1; j < columns_ - 1; j++) {
    board_[0][j].Change_State(wall_h); 
    board_[rows_ - 1][j].Change_State(wall_h); 
  } 

  return;
}

Cell World::Get_Cell(Position pos) {
  return board_[pos.Get_x()][pos.Get_y()]; 
}

void World::Obstacule_Random(int porcentage) {
  int area = (rows_ - 2) * (columns_ - 2); 
  int number_obstacules, random_x, random_y; 
  std::srand(time(NULL)); 

  number_obstacules = area * (((float)porcentage) / ((float)100)); 
  for (int i = 1; i <= number_obstacules; i++) {
    random_x = std::rand()%((rows_ - 2) - (1) + 1) + 1; 
    random_y = std::rand()%((columns_ - 2) - (1) + 1) + 1;
    if ((board_[random_x][random_y].Get_State() == obstacule) || (board_[random_x][random_y].Is_Used())) {
      //i--;  
    } else {
      //board_[random_x][random_y].Change_State(obstacule); 
    }
    board_[random_x][random_y].Change_State(obstacule);
    obstacules_ = i;   
  }
  return; 
}

void World::Obstacule_Manual(std::string file_name) {
  std::ifstream file; 
  int aux;  

  file.open(file_name,std::ios::in); 

  if (file.fail()) {
    std::cout << "ERROR : The file could not be opened" << std::endl; 
    exit(1); 
  }

  file >> aux; 
  obstacules_ = aux; 

  for (int i = 0; i < obstacules_; i++) {
    int x, y; 
    file >> x;
    file >> y;
    if ((x < 0) || (x > rows_) || (y < 0) || (y > columns_)) {
      std::cout << "ERROR : Invalid obstacle position --> (" << x << "," << y << ")" << std::endl; 
      std::cout << "RESOLUTION : Obstacle ignored" << std::endl; 
      system("pause"); 

    } else {
      board_[x][y].Change_State(obstacule);      
    }
  }

  file.close(); 
  return; 
}

bool World::Are_Obstacules(Position position) {
  if (board_[position.Get_x()][position.Get_y()].Get_State() == obstacule) {
    return true; 
  }
  return false; 
}

bool World::Are_Visited(Position position) {
  if (board_[position.Get_x()][position.Get_y()].Get_State() == visited) {
    return true; 
  }
  return false; 
}

void World::Print_World(Position object) {
  std::string aux; 
  char state;
  int counter;  

  board_[object.Get_x()][object.Get_y()].Activate();
  board_[object.Get_x()][object.Get_y()].Change_State(visited);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < columns_; j++) {
      state = board_[i][j].Print_Cell();
      aux.push_back(state);
    }
    aux.push_back('\n'); 
  }
  std::cout << aux; 

  board_[object.Get_x()][object.Get_y()].Desactivate();
  return;
}

void World::Counter_Obstacules() {
  std::cout << obstacules_ << std::endl; 
  return; 
}

void World::Clear() {
  system("cls"); 
}

World& World::operator= (const World& world) {
  this->rows_ = world.rows_; 
  this->columns_ = world.columns_; 
  this->board_ = world.board_; 
  return *this; 
}