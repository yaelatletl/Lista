/* Lista.h
Roberto Aguirre Coyotzi
Yael Atletl Bueno Rojas
Angel Sanchez Cabrera
Leonardo Emmanuel Perez Ocampo*/
#include <stdio.h>

#define MAX 50

typdef struct Node {
  int dato;
  struct Node *sig;
} Nodo;

class Lista{
protected:

Nodo *Lista;

public:
bool lista_vacia(){
       if(Lista==NULL){ printf("Lista vacia\n"); return true; }//significa lista vacia
       else return false; //significa lista no vacia
   }

//recuperar primero

int recuperar_primero(){

if(lista_vacia()) return -1;
else {
  return Lista->dato;
 }
}

//recuperar ultimo
int recuperar_ultimo(){
  Nodo *temp;
if(lista_vacia()){
  printf("Lista vacia\n");
  return -1;}
  else {
  temp = Lista;
  while(temp->sig!=NULL) temp = temp->sig;
  return temp->dato;
  }
}

int recuperar_predecesor(int x){
  Nodo *temp, *temp2;
  if(lista_vacia()) return -1;
  temp = Lista;
  temp2 = temp;
  while (temp->sig!=NULL) {
    temp2 = temp;
    if (temp->dato==x) break;
    temp = temp->sig;
  }
  if (temp2 == Lista){
    printf("No hay antecesor\n");
    return -1;}
  else{
    return temp2->dato;
  }
}

//recuperar predecesor
int recuperar_sucesor(int x){
if(lista_vacia()) return -1;
else {
  temp = temp2 = Lista;
  while (temp->sig!=NULL) {
    temp2 = temp;
    temp = temp->sig;
    if (temp2->dato == x) break;
  }
  if (temp==NULL){ printf("No hay sucesor para este numero\n"); return -1;}
  return temp->dato;}
}

int recuperar_pos_elemento(int x){
  Nodo *temp;
  int i = 0;
temp = Lista;
if(lista_vacia()) return -1;
  while (temp->sig!=NULL) {
    if (temp->dato==x) return i;
    temp = temp->sig;
    i++;
  }
  printf("No se encontró el numero\n");
  return -1;
}

//recuperar un elemento
int recuperar_elemento(int pos){
int i=0;
if(lista_vacia()) return -1;
  while (temp->sig != NULL) {
    if (i==pos) return temp->dato;
    temp = temp->sig;
    i++;
  }
  printf("No hay tal cantidad de posiciones\n");
  return -1;
}

//Insertar

void insertar_inicio(int x){
  Nodo *temp;
  temp = malloc(sizeof(Nodo));
  temp->sig = Lista;
  Lista = temp;
  temp->dato = x;
}

void insertar_final(int x){
  Nodo *temp, *aux;
  temp->sig = NULL;
  temp->dato = x;
  if (lista_vacia()) Lista = temp;
  while(aux->sig!=NULL) aux = aux->sig;
  aux->sig = temp;
}
//Suprimir
int suprimir_primero(){
  int aux;
  Nodo *temp, *temp2;
  if(Lista==NULL) return -1;
  temp = Lista;
  aux = Lista->dato;
  Lista = Lista->sig;
  dispose(temp);
  return aux;
  }


int suprimir_ultimo(){
  int aux;
  Nodo *temp, *temp2;
  if(Lista==NULL) return -1;
  temp = Lista;
  do{
    temp2 = temp;
    temp = temp->sig;
  }while(temp->sig!=NULL);
  aux = temp->dato;
  temp2->sig = NULL;
  dispose(temp);
  return aux;
}

//Eliminar duplicados

void eliminar_duplicados(){
  Nodo *temp, *temp2;
	if (lista_vacia()) return;
  temp = Lista;
  while(temp->sig!=NULL){
    temp2 = temp;
    while(temp2->sig!=NULL){
      if((temp!=temp2)&&(temp->dato == temp2->dato)){
        temp->sig = temp2->sig;
        dispose(temp2);
        eliminar_duplicados();
      }
      temp2 = temp2->sig;

    }
    temp = temp->sig;
  }
}



void mostrar_elementos(){
  Nodo *temp;
  if(lista_vacia()) return;
  temp = Lista;
  while(temp->sig!=NULL){
    printf("%d\n", temp->dato);
    temp = temp->sig;
  }
}
};

class Pila: public Lista{
public:
  void push(int x){
    insertar_final(x);
  }
  int pop(){
    return suprimir_ultimo();
  }
  int ultimo(){
    return recuperar_ultimo();
  }
  void estado(){
      if(lista_vacia()==0){
          printf("La Pila esta vacia \n");
      }else if(lista_vacia()==-1){
              printf("La Pila esta llena \n");
      }else {
          printf("La Pila esta disponible \n");
      }
  }
};



class Cola: public Lista{
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
  void estado(){
      if(lista_vacia()==0){
          printf("La Cola esta vacia \n");
      }else if(lista_vacia()==-1){
              printf("La Cola esta llena \n");
      }else {
          printf("La cola esta disponible \n");
      }
  }
};
