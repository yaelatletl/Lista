//Manejo de librerias
#ifdef S 
#include "Lista_ligada.h"
#endif

#ifdef D 
#include "Lista_doble_ligada_circular.h"
#endif

#ifndef D
#ifndef S
#include "Lista_doble_ligada.h"

#endif
#endif 
//Manejo de excepciones pila
class Pila: public Lista{
public:
  void push(int x, int* bandera){
    insertar_final(x, bandera);
    
  }//Manejo de excepcion suprimir
  int pop(int* bandera){
    return suprimir_ultimo(bandera);
    if (*bandera!=OK) printf("No se pudo hacer pop\n");
  }//Manejo de excepcion recuperar ultimo
  int ultimo(int* bandera){
    return recuperar_ultimo(bandera);
    if (*bandera!=OK) printf("No se pudo recuperar ultimo\n");
  }//Manejo de estado
  void estado(int* bandera){
      if(lista_vacia(bandera)){
          printf("La Pila esta vacia \n");
      }else {
          printf("La Pila esta disponible \n");
      }
  }
};


//Manejo de excepciones cola
class Cola: public Lista{
public:
  void encolar(int x, int* bandera){
    insertar_final(x, bandera);
  }
//Manejo de excepcion desencolar
  int desencolar(int* bandera){
    return suprimir_primero(bandera);
    if (*bandera!=OK) printf("No se puede deseconlar\n");
  }//Manejo de excepcion recupear posicion de elemento
  int recuperar(int x, int* bandera){
    return recuperar_pos_elemento(x, bandera);
    if (*bandera!=OK) printf("No se puede recuperar la posicion del elemento %d\n", x);
  }//Manejo de estado
  void estado(int* bandera){
      if(lista_vacia(bandera)){
          printf("La Cola esta vacia \n");
      }else {
          printf("La cola tiene elementos\n");
      }
  }
};
