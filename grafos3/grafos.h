#include "Lista_doble_ligada.h"

class Enlace{
public:
  NodoGrafo *origen;
  NodoGrafo *destino;
  int peso;
}

class NodoGrafo: public Lista{
public:
  char id;
  bool visitado;
  void agregar_enlace();
  void mostar_adyacentes();
  void obtener_adyacente(int pos);
  }

class Grafo: public Lista{
public:
  bool no_dirigido;
  bool agregar_enlace();
}
