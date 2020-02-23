/* Lista.h
Roberto Aguirre Coyotzi
Yael Atletl Bueno Rojas
Angel Sanchez Cabrera
Leonardo Emmanuel Perez Ocampo*/
#include <stdio.h>
#include <stdlib.h>
#define OK 0
#define MAX 50

typedef struct Node {
  int dato;
  struct Node *sig;
} Nodo;

class Lista{
protected:

Nodo *Lista;

public:
bool lista_vacia(int* bandera){
       if(Lista==NULL){ printf("Lista vacia\n"); *bandera=1; return true; }//significa lista vacia
       else {
         *bandera = OK;
         return false; //significa lista no vacia
   }
 }

//recuperar primero

int recuperar_primero(int * bandera){

if(lista_vacia(bandera)) return -1;
else {
  return Lista->dato;
 }
}

//recuperar ultimo
int recuperar_ultimo(int* bandera){
  Nodo *temp;
if(lista_vacia(bandera)){return -1;}
  else {
  temp = Lista;
  while(temp->sig!=NULL) temp = temp->sig;
  return temp->dato;
  }
}

int recuperar_predecesor(int x, int* bandera){
  Nodo *temp, *temp2;
  if(lista_vacia(bandera)) return-1;
  temp = Lista;
  temp2 = temp;
  while (temp->sig!=NULL) {
    temp2 = temp;
    if (temp->dato==x) break;
    temp = temp->sig;
  }
  if (temp2 == Lista){
    printf("No hay antecesor\n");
    *bandera = 1;
    return -1;}
  else{
    return temp2->dato;
  }
}

//recuperar predecesor
int recuperar_sucesor(int x, int* bandera){
	Nodo *temp, *temp2;
if(lista_vacia(bandera)) return -1;
else {
  temp = temp2 = Lista;
  while (temp->sig!=NULL) {
    temp2 = temp;
    temp = temp->sig;
    if (temp2->dato == x) break;
  }
  if (temp==NULL){ printf("No hay sucesor para este numero\n"); *bandera = 1; return -1;}
  return temp->dato;}
}

int recuperar_pos_elemento(int x, int* bandera){
  Nodo *temp;
  int i = 0;
temp = Lista;
if(lista_vacia(bandera)) return -1;
  while (temp->sig!=NULL) {
    if (temp->dato==x) return i;
    temp = temp->sig;
    i++;
  }
  printf("No se encontro el numero\n");
  *bandera = 1;
  return -1;
}

//recuperar un elemento
int recuperar_elemento(int pos, int* bandera){
	Nodo *temp;
int i=0;
if(lista_vacia(bandera)) return -1;
  while (temp->sig != NULL) {
    if (i==pos) return temp->dato;
    temp = temp->sig;
    i++;
  }
  printf("No hay tal cantidad de posiciones\n");
  *bandera = 1;
  return -1;
}

//Insertar

void insertar_inicio(int x){
  Nodo *temp;
  temp = (Nodo *)malloc(sizeof(Nodo));
  temp->sig = Lista;
  Lista = temp;
  temp->dato = x;
}

void insertar_final(int x, int* bandera){
  Nodo *temp, *aux;
  temp->sig = NULL;
  temp->dato = x;
  if (lista_vacia(bandera)) {*bandera = OK;
  Lista = temp;}
  while(aux->sig!=NULL) aux = aux->sig;
  aux->sig = temp;
}
//Suprimir
int suprimir_primero(int* bandera){
  int aux;
  Nodo *temp, *temp2;
  if(lista_vacia(bandera)) return -1;
  temp = Lista;
  aux = Lista->dato;
  Lista = Lista->sig;
  free(temp);
  return aux;
  }


int suprimir_ultimo(int* bandera){
  int aux;
  Nodo *temp, *temp2;
  if(lista_vacia(bandera)) return -1;
  temp = Lista;
  do{
    temp2 = temp;
    temp = temp->sig;
  }while(temp->sig!=NULL);
  aux = temp->dato;
  temp2->sig = NULL;
  free(temp);
  return aux;
}

//Eliminar duplicados

void eliminar_duplicados(int* bandera){
  Nodo *temp, *temp2;
	if (lista_vacia(bandera)) return;
  temp = Lista;
  while(temp->sig!=NULL){
    temp2 = temp;
    while(temp2->sig!=NULL){
      if((temp!=temp2)&&(temp->dato == temp2->dato)){
        temp->sig = temp2->sig;
        free(temp2);
        eliminar_duplicados(bandera);
      }
      temp2 = temp2->sig;

    }
    temp = temp->sig;
  }
}



void mostrar_elementos(int* bandera){
  Nodo *temp;
  if(lista_vacia(bandera)) {printf("No hay elementos a mostrar \n"); return;}
  temp = Lista;
  while(temp->sig!=NULL){
    printf("%d\n", temp->dato);
    temp = temp->sig;
  }
}
};
