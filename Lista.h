/* Lista.h*/
#include <stdio.h>

#define MAX 50
class Lista{
protected:

int lista[MAX];
int index;


public:
//recuperar primero
int recurperar_primero(){

if(estado_lista() == 0){
  printf("lista vacia\n");;
}else {
  printf("%d\n",lista[0]);
 }
}

//recuperar ultimo
int recurperar_utlimo(){

if(estado_lista() == 0){
  printf("lista vacia\n");
}else {
  printf("%d", lista[index-1]);
  }
}

//recuperar sucesor
int recurperar_sucesor(int x){

if(estado_lista() == 0){
  printf("lista vacia\n");
}else {
  if (x+1 > index) {
   printf("%d\n", lista[x+1]);
  }
}

//recuperar predecesor
int recurperar_predecesor(int x){

if(estado_lista() == 0) printf("lista vacia\n");
else {
  if ( x > 0 && ! x > index) {
   printf("%d\n", lista[x-1]);
  }
}

//recuperar un elemento
int recuperar_elemento(int x){

if(Lista == 0){
  printf("lista vacia\n");
  }else{
 if (x > index && x <= MAX) {
  printf("%d\n", lista[x]);
  }
}

void mostrar_lista(){

  if(Lista == 0){
  printf("lista vacia\n");
  }else{
  for(i=0;i>index;i++)
    printf("%d\n", lista[i])
  }
}

/*
public int recuperarSecesor(int array[],int posicion,int indice){
   if(posicion<indice){
   for(int i=0;i<indice;i++){
    if((i==posicion)&&(array[(posicion+1)]!=0)){
        return array[(posicion+1)];
    }
    }
   }
    System.out.println("no hay sucesor");
    return -1;
}

public int recuperrarElemento(int array[],int posicion, int indice){
    for(int i=0;i<indice;i++){
        if(i==posicion){
            return array[i];
        }
    }
    System.out.println("no existe el elemento digitado");
    return -1;
//Mostrar lista

   public int recuperarPredesecesor(int array[],int posicion,int indice){
   if(posicion<indice){
   for(int i=0;i<indice;i++){
    if((i==posicion)&&(array[(posicion-1)]!=0)){
        return array[(posicion-1)];
    }
    }
   }
    System.out.println("no hay predecesor");
    return -1;
}
*/
int estado_lista(){
       if(index==0){
           return 0; //significa lista vacia
       }else if(index==50){
           return -1; //significa lista llena
       } else
           return 1; //puede cocuparse la lista
   }

}

}
