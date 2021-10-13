#include "simulation.h"

int main() {

  int filas = 30, columnas = 25; 
  unsigned int max_time = 100; 
  int porcentage = 30;
  int x = 10 , y = 15;
  int z = 20 , w = 20;  

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
  Car taxi(start); 
  World world(filas,columnas); 
  Simulation Game(taxi, world);

  Game.Play(porcentage, max_time); 

  return 0; 
}