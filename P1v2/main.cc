#include "simulation_node.h"

void Edit_Terminal(); 

int main() {

  int filas = 5, columnas = 5; 
  int x = 1 , y = 1;
  int z = 5 , w = 5; 
  int small_rows = 100, small_columns = 100; 
  int big_rows = 200, big_columns= 200;   
  int opcion, definicion; 
  Position start(10,10); 
  Position end(50,50); 
  Position end_small(100,100); 
  Position end_big(200,200); 
  SimNode* Game; 

  while (opcion != 5) {
    system("cls"); 
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
      
      Game = new SimNode(filas,columnas,start,end);
      Game->Play();  
      break;
    
    case 2: 
      system("cls"); 
      std::cout << "0 - Escenario: Sin Obstaculos - Grande\n"; 
      std::cout << "1 - Escenario: Sin Obstaculos - Pequeno\n"; 
      std::cout << "Elección: "; 
      std::cin >> definicion; 
      if (definicion) {
        Game = new SimNode(small_rows, small_columns, start, end_small);  
        Game->Play_NoObstacule(); 
      } else {
        Game = new SimNode(big_rows, big_columns, start, end_big); 
        Game->Play_NoObstacule(); 
      }
      break; 
    
    case 3: 
      system("cls"); 
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
        Game = new SimNode(small_rows, small_columns, start, end_small);
        Game->Play_Obstacule(25); 
        break;
      case 1: 
        Game = new SimNode(small_rows, small_columns, start, end_small);
        Game->Play_Obstacule(50); 
        break;
      case 2: 
        Game = new SimNode(small_rows, small_columns, start, end_small);
        Game->Play_Obstacule(80); 
        break;
      case 3: 
        Game = new SimNode(big_rows,big_columns, start, end_big);
        Game->Play_Obstacule(25); 
        break;
      case 4: 
        Game = new SimNode(big_rows,big_columns, start, end_big);
        Game->Play_Obstacule(50); 
        break;
      case 5: 
        Game = new SimNode(big_rows,big_columns, start, end_big);
        Game->Play_Obstacule(80); 
        break;      
      default:
        break;
      }
      break;

    case 4: 
      Edit_Terminal(); 
      std::cout << "PRUEBA EXPERIMENTAL" << std::endl; 
      std::cout << "####################################" << std::endl; 
      std::cout << "Escenario 1: Sin Obstaculos - Pequeno - Rectilinea - 4 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(0,0,0,0); 
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 2: Sin Obstaculos - Pequeno - Rectilinea - 8 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(0,0,0,1);
      system("pause");  
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 3: Sin Obstaculos - Pequeno - Euclidea - 4 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(0,0,1,0);
      system("pause");  
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 4: Sin Obstaculos - Pequeno - Euclidea - 8 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(0,0,1,1);
      system("pause");  
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 5: Sin Obstaculos - Grande - Rectilinea - 4 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(0,0,0,0);
      system("pause");  
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 6: Sin Obstaculos - Grande - Rectilinea - 8 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(0,0,0,1);
      system("pause");  
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 7: Sin Obstaculos - Grande - Euclidea - 4 direcciones" << std::endl; 
      //Game = new SimNode(big_rows, big_columns, start, end_big); 
      //Game->Play_Experimental(0,0,1,0);
      system("pause");  
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 8: Sin Obstaculos - Grande - Euclidea - 8 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(0,0,1,1);
      system("pause");  
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 9: Obstaculos - 25 - Pequeno - Rectilinea - 4 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,25,0,0); 
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 10: Obstaculos - 50 - Pequeno - Rectilinea - 4 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,50,0,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 11: Obstaculos - 80 - Pequeno - Rectilinea - 4 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,80,0,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 12: Obstaculos - 25 - Pequeno - Rectilinea - 8 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,25,0,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 13: Obstaculos - 50 - Pequeno - Rectilinea - 8 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,50,0,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 14: Obstaculos - 80 - Pequeno - Rectilinea - 8 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,80,0,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 15: Obstaculos - 25 - Pequeno - Euclidea - 4 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,25,1,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 16: Obstaculos - 50 - Pequeno - Euclidea - 4 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,50,1,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 17: Obstaculos - 80 - Pequeno - Euclidea - 4 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,80,1,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 18: Obstaculos - 25 - Pequeno - Euclidea - 8 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,25,1,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 19: Obstaculos - 50 - Pequeno - Euclidea - 8 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,50,1,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 20: Obstaculos - 80 - Pequeno - Euclidea - 8 direcciones" << std::endl; 
      Game = new SimNode(small_rows, small_columns, start, end_small); 
      Game->Play_Experimental(1,80,1,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 21: Obstaculos - 25 - Grande - Rectilinea - 4 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,25,0,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 22: Obstaculos - 50 - Grande - Rectilinea - 4 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,50,0,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 23: Obstaculos - 80 - Grande - Rectilinea - 4 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,80,0,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 24: Obstaculos - 25 - Grande - Rectilinea - 8 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,25,0,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 25: Obstaculos - 50 - Grande - Rectilinea - 8 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,50,0,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 26: Obstaculos - 80 - Grande - Rectilinea - 8 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,80,0,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 27: Obstaculos - 25 - Grande - Euclidea - 4 direcciones" << std::endl; 
      //Game = new SimNode(big_rows, big_columns, start, end_big); 
      //Game->Play_Experimental(1,25,1,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 28: Obstaculos - 50 - Grande - Euclidea - 4 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,50,1,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 29: Obstaculos - 80 - Grande - Euclidea - 4 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,80,1,0);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 30: Obstaculos - 25 - Grande - Euclidea - 8 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,25,1,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 31: Obstaculos - 50 - Grande - Euclidea - 8 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,50,1,1);
      system("pause"); 
      std::cout << "####################################" << std::endl;
      std::cout << "Escenario 32: Obstaculos - 80 - Grande - Euclidea - 8 direcciones" << std::endl; 
      Game = new SimNode(big_rows, big_columns, start, end_big); 
      Game->Play_Experimental(1,80,1,1);
      system("pause"); 
      break; 
    
    default:
      break;
    }
  }

  delete Game; 
  return 0; 
}

void Edit_Terminal() {
  system("COLOR F"); 
  system("MODE 1000,1000");
  system("cls");   
  return; 
}
