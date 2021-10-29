#include "simulation_node.h"

int main() {

  int filas = 5, columnas = 5; 
  int x = 1 , y = 1;
  int z = 5 , w = 5; 
  int small_rows = 250, small_columns = 250; 
  int big_rows = 500, big_columns= 500;   
  int opcion, definicion; 
  Position start(1,1); 
  Position end(100,150); 
  Position end_small(250,250); 
  Position end_big(500,500); 
  SimNode Game; 

  while (opcion != 5) {
    system("clear"); 
    std::cout << "MENU" << std::endl; 
    std::cout << "--> Opcion 1: Simulacion Estandar\n"; 
    std::cout << "--> Opcion 2: Escenario - Sin Obstáculos\n"; 
    std::cout << "--> Opcion 3: Escenario - Obstaculos\n"; 
    std::cout << "--> Opcion 4: Prueba Experimental Completa (Modo Tablas)\n";  
    std::cout << "--> Opcion 5: EXIT\n" << std::endl; 

    std::cout << "Insertar opcion: "; 
    std::cin >> opcion;  

    switch (opcion)
    {
    case 1:      
      /* Entrada por consola */
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
      start.Set_Position(x,y);  
      end.Set_Position(z,w);
      Game.Create(filas,columnas,start,end);
      Game.Play(); 
      Game.Eliminate(); 
      break;
    
    case 2: 
      system("clear"); 
      std::cout << "0 - Escenario: Sin Obstaculos - Grande\n"; 
      std::cout << "1 - Escenario: Sin Obstaculos - Pequeno\n"; 
      std::cout << "Elección: "; 
      std::cin >> definicion; 
      if (definicion) {
        Game.Create(small_rows, small_columns, start, end_small); 
        Game.Play_NoObstacule(); 
        Game.Eliminate(); 
      } else {
        Game.Create(big_rows, big_columns, start, end_big); 
        Game.Play_NoObstacule(); 
        Game.Eliminate(); 
      }
      break; 
    
    case 3: 
      system("clear"); 
      std::cout << "0 - Escenario: Obstaculos - Pequeño - 25%\n"; 
      std::cout << "1 - Escenario: Obstaculos - Pequeño - 50%\n";
      std::cout << "2 - Escenario: Obstaculos - Pequeño - 80%\n";
      std::cout << "3 - Escenario: Obstaculos - Grande - 25%\n";
      std::cout << "4 - Escenario: Obstaculos - Grande - 50%\n";
      std::cout << "5 - Escenario: Obstaculos - Grande - 80%\n";
      std::cout << "Inserte elección: "; 
      std::cin >> definicion; 

      switch (definicion)
      {
      case 0:
        Game.Create(small_rows, small_columns, start, end_small);
        Game.Play_Obstacule(25);
        Game.Eliminate(); 
        break;
      case 1: 
        Game.Create(small_rows, small_columns, start, end_small);
        Game.Play_Obstacule(50);
        Game.Eliminate(); 
        break;
      case 2: 
        Game.Create(small_rows, small_columns, start, end_small);
        Game.Play_Obstacule(80);
        Game.Eliminate(); 
        break;
      case 3: 
        Game.Create(big_rows,big_columns, start, end_big);
        Game.Play_Obstacule(25);
        Game.Eliminate(); 
        break;
      case 4: 
        Game.Create(big_rows,big_columns, start, end_big);
        Game.Play_Obstacule(50);
        Game.Eliminate(); 
        break;
      case 5: 
        Game.Create(big_rows,big_columns, start, end_big);
        Game.Play_Obstacule(80);
        Game.Eliminate(); 
        break;      
      default:
        break;
      }
      break;

    case 4: 

      break; 
    
    default:
      break;
    }
  }

}