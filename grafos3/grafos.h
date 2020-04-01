#include "derivados.h"

class NodoGrafo: public Lista{
public:

  //Variables
  int bandera;
  char id;
  bool visitado;
  bool no_dirigido;
  NodoGrafo *anterior; //Para uso en Dijkstra
  int peso;


  //Funciones de inicialización
  void agregar_arista(char id_origen , char id_destino, bool bidireccional){
  Enlace *artista_actual;
  NodoGrafo *inicio, *final;
  *artista_actual = new Enlace; //crear un Enlace

  inicio = obtener_nodo(id_origen);//Verificar si existe nodo con id_origen o id_destino
  final = obtener_nodo(id_destino);//Verificar si existe nodo con id_origen o id_destino
  if (inicio!=NULL)   inicio = new NodoGrafo;//Si no existe alguno, crearlo y añadirlo al enlace
  artista_actual->origen = inicio;
  if (final!=NULL)    final = new NodoGrafo;//Si no existe alguno, crearlo y añadirlo al enlace
  artista_actual->destino = final;

  if (bidireccional) agregar_arista(id_destino, id_origen, false); //Si es bidireccional, se hace un agregar_arista(char id_destino, char id_origen, false)
  insertar_final(&Enlace, &bandera); //Agregar el enlace a las adyacencias
  return;
  }
  


  void mostar_adyacentes();
  NodoGrafo *obtener_adyacente(int pos, int* bandera){
    return (NodoGrafo*)recuperar_elemento(pos, bandera);
  }
  NodoGrafo obtener_arbol_minimo(char id_origen);
  bool existe_conexion(char id_origen, char id_destino);
  NodoGrafo *obtener_nodo(char id); //Obtiene un nodo atravéz de la id, regresa NULL si no existe
  void imprimir_grafo();
};

class Enlace{
public:
  NodoGrafo *origen;
  NodoGrafo *destino;
  int peso;
  Enlace(char id_origen, char id_destino){


  }

  char get_id_origen(){
    return (NodoGrafo*)origen->id;
  }

  char get_id_destino(){
    return (NodoGrafo*)destino->id;
  }

};
