#include "derivados.h"
class Enlace;
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
  NodoGrafo();
  void agregar_arista(char id_origen , char id_destino, int peso, bool bidireccional, int *bandera);


  //Funciones de visualizacion
  void mostrar_adyacentes(int *bandera);
  void mostrar_elementos(int* bandera);
  void mostrar_dijkstra(char id, int* bandera);
  //Recorridos
  NodoGrafo *obtener_nodo_adyacente(int pos, int* bandera);
  Enlace *obtener_enlace_adyacente(int pos, int* bandera);
  NodoGrafo *obtener_arbol_minimo(char id_origen); //Via kurskal
  NodoGrafo *buscar_nodo_profundidad(char id); //Obtiene un nodo atravez de la id, por profundidad, regresa NULL si no existe
  NodoGrafo *buscar_nodo_ancho(char id); //Obtiene un nodo atravez de la id, por ancho, regresa NULL si no existe
  NodoGrafo *calcular_dijkstra(char id, int peso_inicial, NodoGrafo *actual, int *bandera); //Calcula un camino utilizando Dijkstra y regresa el nodo final si existe, sino regresa NULL


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

//FUNCIONES DE GRAFOS/NODOS ############################
NodoGrafo::NodoGrafo(){
	peso=-1;
}
void NodoGrafo::mostrar_dijkstra(char id, int *bandera){
	NodoGrafo *Meta;
	Meta = calcular_dijkstra(id, 0, this, bandera);
	if (Meta!=NULL){
		printf("El peso del camino es %d \n El recorrido es: \n", Meta->peso);
		while(Meta!=NULL){
			printf("%c<-", Meta->id);
			Meta = Meta->anterior;
		}
		printf("\n");
	}
	else printf("No existe un nodo con id = &d o es inaccesible", id);
}
NodoGrafo* NodoGrafo::calcular_dijkstra(char id, int peso_inicial, NodoGrafo *actual, int *bandera){
  Enlace *temp;
  NodoGrafo *verificador;
  int nuevo_peso, pos = 0;
  if(peso==-1){
    peso = peso_inicial;
  }
  else{
    if (peso>peso_inicial){
      peso = peso_inicial;
      anterior = actual; //Referencia de acceso rápido,
    }
  }
  visitado = true;
  if(this->id==id){
    return this;
  }
  do{
  	temp = obtener_enlace_adyacente(pos++, bandera);
  	if (temp!=NULL){
      nuevo_peso = peso_inicial + temp->peso;
      if (temp->destino->visitado==false){
      	verificador = temp->destino->calcular_dijkstra(id, nuevo_peso, this, bandera);
      	if(verificador!=NULL){
      		return verificador;
		  }
	  }
      
	  }
  }while (temp!=NULL);
  return NULL;
}

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

NodoGrafo* NodoGrafo::obtener_nodo_adyacente(int pos, int* bandera){
  return (NodoGrafo*)((Enlace*)recuperar_elemento(pos, bandera))->destino;
}


Enlace* NodoGrafo::obtener_enlace_adyacente(int pos, int* bandera){
  return ((Enlace*)recuperar_elemento(pos, bandera));
}


void NodoGrafo::mostrar_adyacentes(int *bandera){
  NodoGrafo *temp;
  int pos = 0;
  do{
  	temp = obtener_nodo_adyacente(pos++, bandera);
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
