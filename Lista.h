/* Lista.h*/
#include <stdio.h>

#define MAX 50
class Lista{
protected:

int lista[MAX];
int index = 0;


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
  if (x+1 < index) {
   return lista[x+1]);
  }
}

//recuperar predecesor
int recurperar_predecesor(int x){

if(estado_lista() == 0) printf("lista vacia\n");
else {
  if ( x > 0 &&  x < index) {
   return lista[x-1];
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

//Insertar

void insertar_inicio(int x){
	int aux=0;
	if(estado_lista()==0){
		lista[0]=x;
		return;
	}
	if(estado_lista()==-1){
		printf("Lista llena\n");
		return;
	}
	else{
		aux = index-1;
		while(aux>=0){
			lista[aux+1]=lista[aux];
			aux--;
		}
		lista[aux+1] = x;
		indice++;
		return;
	}
}

void insertar_final(int x){
	if (estado_lista()==-1){
		printf("Lista llena\n")
		return;
	}
	else{
		lista[index]=x;
		index++;
		return;
	}
}


//Suprimir


int suprimir_primero(){
	int temp = -1;
	if(estado_lista==0){
		printf("Lista vacia\n");
		
	}
	else{
		temp = lista[0];
		for (int i=1; i<index; i++){
			lista[i-1]=lista[i];
		}
		index--;
		
	}
	return temp;
}

int suprimir_ultimo(){
	int temp = -1;
	if(estado_lista()==0){
		printf("lista vacia\n");
		
	}
	else {
		temp=lista[index-1];
		index--;
		
	}
	return temp;
}

//Eliminar duplicados

void eliminar_duplicados(){
	if (estado_lista== 0){
		printf("Lista Vacia\n");
		return;
	}
	else{
		for (int i =0; i<index; i++){
			for(int j = i+1; j<index; j++){
				if (lista[i]==lista[j]){
					for(int k = j+1; k< index; k++){
						indice--;
						j--;
					}
				}
			}
		}
	}
}



void mostrar_elementos(){

  if(estado_lista() == 0){
  printf("lista vacia\n");
  }else{
  for(int i=0; i<index;i++)
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
       if(index==0) return 0; //significa lista vacia
       else if(index==50) return -1; //significa lista llena
       else return 1; //puede cocuparse la lista
   }

}

}
