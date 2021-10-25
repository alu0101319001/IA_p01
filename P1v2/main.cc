#include "simulation_node.h"

int main() {

  int filas = 5, columnas = 5; 
  int x = 1 , y = 1;
  int z = 5 , w = 5;    

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
  SimNode Game(filas,columnas,start,end);

  Game.Play();

  return 0; 
}