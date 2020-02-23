#ifdef S 
#include "Lista_ligada.h"
#endif

#ifdef D 
#include "Lista_doble_ligada.h"
#endif

#ifndef D
#ifndef S
#include "Lista_doble_ligada_circular.h"
#endif
#endif 

class Pila: public Lista{
public:
  void push(int x, int* bandera){
    insertar_final(x, bandera);
    
  }
  int pop(int* bandera){
    return suprimir_ultimo(bandera);
    if (*bandera!=OK) printf("No se pudo hacer pop\n");
  }
  int ultimo(int* bandera){
    return recuperar_ultimo(bandera);
    if (*bandera!=OK) printf("No se pudo recuperar ultimo\n");
  }
  void estado(int* bandera){
      if(lista_vacia(bandera)){
          printf("La Pila esta vacia \n");
      }else {
          printf("La Pila esta disponible \n");
      }
  }
};



class Cola: public Lista{
public:
  void encolar(int x, int* bandera){
    insertar_final(x, bandera);
  }

  int desencolar(int* bandera){
    return suprimir_primero(bandera);
    if (*bandera!=OK) printf("No se puede deseconlar\n");
  }
  int recuperar(int x, int* bandera){
    return recuperar_pos_elemento(x, bandera);
    if (*bandera!=OK) printf("No se puede recuperar la posicion del elemento %d\n", x);
  }
  void estado(int* bandera){
      if(lista_vacia(bandera)){
          printf("La Cola esta vacia \n");
      }else {
          printf("La cola tiene elementos\n");
      }
  }
};
