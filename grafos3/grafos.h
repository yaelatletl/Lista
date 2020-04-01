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


  //Funciones de inicializacion
  void agregar_arista(char id_origen , char id_destino, int peso, bool bidireccional);



  void mostrar_adyacentes(int *bandera);
  void mostrar_elementos(int* bandera);

  //Recorridos
  NodoGrafo *obtener_adyacente(int pos, int* bandera);
  NodoGrafo *obtener_arbol_minimo(char id_origen); //Via kurskal
  NodoGrafo *buscar_nodo_profundidad(char id); //Obtiene un nodo atravez de la id, regresa NULL si no existe
  NodoGrafo *buscar_nodo_ancho(char id); //Obtiene un nodo atravez de la id, regresa NULL si no existe
  bool calcular_dijkstra(char id);


  bool existe_conexion(char id_origen, char id_destino);

};

class Enlace{
public:
  NodoGrafo *origen;
  NodoGrafo *destino;
  int peso;
  Enlace(NodoGrafo *orig, NodoGrafo *dest, int pes);
  char get_id_origen();
  char get_id_destino();
};


void NodoGrafo::mostrar_elementos(int* bandera){
Nodo *temp;
if(lista_vacia(bandera)) return;
temp = Lista;
do{
  printf("%c-->%c\n", ((Enlace*)(temp->dato))->origen->id, ((Enlace*)(temp->dato))->destino->id);
  ((NodoGrafo*)(((Enlace*)(temp->dato))->destino))->mostrar_elementos(bandera);
  temp = temp->sig;
  }while(temp!=NULL);
}

NodoGrafo* NodoGrafo::obtener_adyacente(int pos, int* bandera){
  return (NodoGrafo*)((Enlace*)recuperar_elemento(pos, bandera))->destino;
}

void NodoGrafo::mostrar_adyacentes(int *bandera){
  NodoGrafo *temp;
  int pos = 0;
  do{
  	temp = obtener_adyacente(pos++, bandera);
  	if (temp!=NULL){
  		printf("%c\n", temp->id);
	  }

  }while(temp!=NULL);
}

void NodoGrafo::agregar_arista(char id_origen , char id_destino, int peso, bool bidireccional, int *bandera){
Enlace *arista_actual;
NodoGrafo *inicio, *final;

inicio = obtener_nodo(id_origen);//Verificar si existe nodo con id_origen o id_destino
final = obtener_nodo(id_destino);//Verificar si existe nodo con id_origen o id_destino
if (inicio!=NULL)   inicio = new NodoGrafo;//Si no existe alguno, crearlo y añadirlo al enlace
if (final!=NULL)    final = new NodoGrafo;//Si no existe alguno, crearlo y añadirlo al enlace
arista_actual = new Enlace(inicio, final, peso); //crear un Enlace

if (bidireccional) {final->agregar_arista(id_destino, id_origen, peso, false, bandera);} //Si es bidireccional, se hace un agregar_arista(char id_destino, char id_origen, false)
insertar_final(arista_actual, bandera); //Agregar el enlace a las adyacencias
return;
}

// FUNCIONES DE ENLACE/(ARISTA) ################################


Enlace::Enlace(NodoGrafo *orig, NodoGrafo *dest, int pes){
  origen = orig;
  destino = dest;
  peso = pes;
}

 char Enlace::get_id_origen(){
   return origen->id;
 }

 char Enlace::get_id_destino(){
   return destino->id;
 }
