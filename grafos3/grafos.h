#include "derivados.h"

class NodoGrafo: public Lista{
public:
  char id;
  bool visitado;
  void agregar_arista();
  void mostar_adyacentes();
  NodoGrafo *obtener_adyacente(int pos);
  };

class Enlace{
public:
  NodoGrafo *origen;
  NodoGrafo *destino;
  int peso;
};



class Grafo: public Lista{
public:
  bool no_dirigido;
  bool agregar_arista(char id_origen, char id_destino);
  /*
  Pseudocodigo:
  
  */
  Grafo obtener_arbol_minimo(char id_origen);
  bool existe_conexion(char id_origen, char id_destino);
  NodoGrafo *obtener_nodo(char id);
};
