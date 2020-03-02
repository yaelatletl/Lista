/* Lista.h
Roberto Aguirre Coyotzi
Yael Atletl Bueno Rojas
Angel Sanchez Cabrera
Leonardo Emmanuel Perez Ocampo*/

/*
Esta es una reimplementacion de la lista doble ligada, que permite almacenar
apuntadores a cualquier tipo.
*/
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define MAX 50

typedef struct Node {
  void *dato;
  struct Node *sig;
  struct Node *ant;
} Nodo;

class ListaDoble{
protected:

Nodo *Lista = NULL;

public:
bool lista_vacia(int* bandera){
	void* dummyPointer;
       if(Lista==NULL){ printf("Lista vacia\n"); *bandera = 1; return true; }//significa lista vacia
       else {

    *bandera = 0;
	   return false;} //significa lista no vacia
   }

//Funcion para recuperar primero

void* recuperar_primero(int* bandera){
	void* dummyPointer;

if(lista_vacia(bandera)) return dummyPointer;
else {
  return Lista->dato;
 }
}

//Funcion para recuperar ultimo
void* recuperar_ultimo(int* bandera){
	void* dummyPointer;
  Nodo *temp;
if(lista_vacia(bandera)){
  return dummyPointer;}
  else {
  temp = Lista;
  while(temp->sig!=NULL) temp = temp->sig;
  return temp->dato;
  }
}

//Funcion para recuperar predecesor
void* recuperar_predecesor(void* x, int* bandera){
	void* dummyPointer;
  Nodo *temp, *temp2;
  if(lista_vacia(bandera)) return dummyPointer;
  temp = Lista;
  temp2 = temp;
   do{
    if (temp->dato==x) break;
    temp = temp->sig;
  }while (temp->sig!=NULL);
  if (temp == Lista){
    printf("No hay antecesor\n");
    return dummyPointer;}
  else{
    if (temp->ant != NULL) return temp->dato;
    else{ printf("No hay antecesor\n"); return dummyPointer;}
  }
}

//Funcion para recuperar sucesor
void* recuperar_sucesor(void* x, int* bandera){
	void* dummyPointer;
	Nodo *temp, *temp2;
if(lista_vacia(bandera)) return dummyPointer;
else {
  temp = temp2 = Lista;
  while (temp->sig!=NULL) {
    temp2 = temp;
    temp = temp->sig;
    if (temp2->dato == x) break;
  }
  if (temp==NULL){ printf("No hay sucesor para este numero\n"); *bandera = 1; return dummyPointer;}
  return temp->dato;}
}

//Funcion para recuperar la posicion del elemento indicado
int recuperar_pos_elemento(void *x, int* bandera){
  Nodo *temp;
  int i = 1;
temp = Lista;
if(lista_vacia(bandera)) return -1;
  do{
    if (temp->dato==x) return i;
    temp = temp->sig;
    i++;
  }while (temp!=NULL);
  printf("No se encontro el numero\n");
  *bandera = 1;
  return -1;
}

//Funcion para recuperar un elemento
void* recuperar_elemento(int pos, int* bandera){
	void* dummyPointer;
	Nodo *temp;
int i=0;
if(lista_vacia(bandera)) return dummyPointer;
  while (temp->sig != NULL) {
    if (i==pos) return temp->dato;
    temp = temp->sig;
    i++;
  }
  printf("No hay tal cantidad de posiciones\n");
  *bandera = 1;
  return dummyPointer;
}

//Funcion para insertar al inicio
void insertar_inicio(void *x, int* bandera){
	void* dummyPointer;
  Nodo *temp;
  temp = (Nodo *)malloc(sizeof(Nodo));

  temp->sig = Lista;
  temp->ant = NULL;
  temp->dato = x;

  if(!lista_vacia(bandera)) Lista->ant=temp;
  Lista = temp;

}

//Funcion para insertar al final
void insertar_final(void *x,int* bandera){
	void* dummyPointer;
  Nodo *temp, *aux;
  temp = (Nodo *)malloc(sizeof(Nodo));
  temp->sig = NULL;
  temp->ant = NULL;
  temp->dato = x;
  if (lista_vacia(bandera)){ Lista = temp; *bandera=OK; return;}
  aux = Lista;
  while(aux->sig!=NULL) {
  aux = aux->sig;  }
  temp->ant = aux;
  aux->sig = temp;
}

//Funcion para suprimir al inicio
void* suprimir_primero(int* bandera){
	void* dummyPointer;
  void* aux;
  Nodo *temp;
  if(lista_vacia(bandera)) return dummyPointer;
  temp = Lista;
  aux = Lista->dato;
  Lista = Lista->sig;
  if (Lista!=NULL) Lista->ant = NULL;
  free(temp);
  return aux;
  }

//Funcion para suprimir al final
void* suprimir_ultimo(int* bandera){
	void* dummyPointer;
  void* aux;
  Nodo *temp;
  if(lista_vacia(bandera)==true) return dummyPointer;
  temp = Lista;
  while(temp->sig!=NULL){

    temp = temp->sig;

  }
  aux = temp->dato;

  if(temp->ant!=NULL) temp->ant->sig = NULL;
  else Lista = NULL;
  free(temp);
  return aux;
}

//Funcion para eliminar duplicados
void eliminar_duplicados(int* bandera){
  Nodo *temp, *temp2;
	if (lista_vacia(bandera)) return;
  temp = Lista;
  while(temp->sig!=NULL){
    temp2 = temp;
    while(temp2->sig!=NULL){
      if((temp!=temp2)&&(temp->dato == temp2->dato)){
        temp->sig = temp2->sig;
        temp2->sig->ant = temp;
        free(temp2);

        eliminar_duplicados(bandera);
        temp2 = temp;
      }
      temp2 = temp2->sig;

    }
    temp = temp->sig;
  }
}


//Funcion para mostrar los elementos
void mostrar_elementos(int* bandera){
  Nodo *temp;
  if(lista_vacia(bandera)) return;
  temp = Lista;
  do{
    printf("%d\n", temp->dato);
    temp = temp->sig;
  }while(temp!=NULL);
}
};
