#include "simulation.h"

int main() {

  int filas = 20, columnas = 20; 
  int x = 10 , y = 10;
  int z = 1 , w = 19;  

  /* Entrada por consola 
  std::cout << "DATOS DE ENTRADA" << std::endl; 
  std::cout << "Filas: "; 
  std::cin >> filas; 
  std::cout << "Columnas: "; 
  std::cin >> columnas; 
  std::cout << "Posicion inicial: " << std::endl; 
  std::cout << "\tx: ";  
  std::cin >> x;
  std::cout << "\ty: ";  
  std::cin >> y;   
  std::cout << "Posicion final:" << std::endl; 
  std::cout << "\tx: ";  
  std::cin >> z;
  std::cout << "\ty: ";  
  std::cin >> w;  
  */
 
  Position start(x,y); 
  Position end(z,w);
  World world(filas,columnas); 
  Simulation Game(world,start,end);

  Game.Play();
  //Game.Test();  

  return 0; 
}