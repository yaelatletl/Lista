#include "derivados.h"
//alguno


class Arbol: public Lista{
  public:
    char id;
    int peso;
    int grado;


    int calcular_peso(){
return 1;
}

};

class ArbolBinario: public Arbol{
public:
  bool esta_lleno();
  void posorden(Arbol nodo){
    if (nodo==NULL) return;
    posorden(nodo.hijo1);
    posorden(nodo.hijo2);
    printf("Nodo %c\n", nodo.id);
  }
  void preorden(Arbol nodo){
    if (nodo==NULL) return;
    printf("Nodo %c\n", nodo.id);
    preorden(nodo.hijo1);
    preorden(nodo.hijo2);
  }
}
