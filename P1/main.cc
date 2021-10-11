#include "simulation.h"

int main() {

  int filas = 20, columnas = 40; 
  unsigned int max_time = 100; 
  int porcentage = 30;
  int x,y; 

  // Entrada por consola 
  std::cout << "Introduzca numero de filas: "; 
  std::cin >> filas; 
  std::cout << "Introduzca numero de columnas: "; 
  std::cin >> columnas; 
  std::cout << "Introduzca posicion inicial (x,y): " << std::endl;  
  std::cout << "x : "; 
  std::cin >> x; 
  std::cout << "y : "; 
  std::cin >> y; 
  std::cout << "Introducir porcentaje de obstaculos: "; 
  std::cin >> porcentage; 

  Position start(x,y); 
  Car taxi(start); 
  World world(filas,columnas); 
  Simulation Game(taxi, world);

  Game.Play(porcentage, max_time); 

  return 0; 
}
