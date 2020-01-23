#include "Lista.h"


class Pila: public Lista{
public:
  void push(int x){
    insertar_final(x);
  }
  int pop(){
    return suprimir_ultimo();
  }
  int ultimo(){
    return recuperar_ultimo();
  }
}
