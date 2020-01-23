##include "Lista.h"

class Cola:
public Lisa{
public:
  void encolar(int x){
    insertar_final(x);
  }

  int desencolar(){
    return suprimir_primero();
  }
  int recuperar(int x){
    return recuperar_pos_elemento(x);
  }
}
