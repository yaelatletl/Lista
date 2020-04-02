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
    Arbol *obtener_hijo(int pos, int *bandera){
      return (Arbol*)recuperar_elemento(pos, bandera);
    }


};

class ArbolBinario: public NodoGrafo{
public:
  bool esta_lleno();
  void posorden(Arbol nodo){
    if (nodo==NULL) return;
    posorden(*(nodo.obtener_hijo(0,bandera)); //hijo1
    posorden(*(nodo.obtener_hijo(1, bandera))); //hijo2
    printf("Nodo %c\n", nodo.id);
  }
  void preorden(Arbol nodo){
    if (nodo==NULL) return;
    printf("Nodo %c\n", nodo.id);
    preorden(*(nodo.obtener_hijo(0, bandera))); //hijo1
    preorden(*(nodo.obtener_hijo(1, bandera))); //hijo2

  void inorden(Arbol nodo){
    if (nodo==null) return;
    preorden(*(nodo.obtener_hijo(0, bandera))); //hijo1
    printf("Nodo %c\n", nodo.id);
    preorden(*(nodo.obtener_hijo(1, bandera))); //hijo2
  }

  }
}
