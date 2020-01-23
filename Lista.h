/* Lista.h
Yael Angel*/
#include <stdio.h>

#define MAX 50


class Lista{
protected:

int lista[MAX];
int index = 0;


public:
int estado_lista(){
       if(index==0) return 0; //significa lista vacia
       else if(index==50) return -1; //significa lista llena
       else return 1; //puede cocuparse la lista
   }

//recuperar primero

int recuperar_primero(){

if(estado_lista() == 0){
  printf("lista vacia\n");;
}else {
  return lista[0];
 }
}

//recuperar ultimo
int recuperar_ultimo(){

if(estado_lista() == 0){
  printf("lista vacia\n");
}else {
  return lista[index-1];
  }
}

int recuperar_sucesor(int x){
   for(int i=0;i<indice;i++){
    if((i==x)&&(array[(i+1)]!=0)){
        return array[(i+1)];
    }
    }
    printf("no hay sucesor");
    return -1;
}

//recuperar predecesor
int recuperar_predecesor(int x){
if(estado_lista() == 0) printf("lista vacia\n");
else {
	for(int i=0; i<index-1; i++)
  if ( x == lista[i]) {
  	if(i=!0) return lista[i-1];
  	else printf("No hay antecesor para este numero\n");
  }
}
}

int recuperar_pos_elemento(int x){

if(estado_lista() == 0){
  printf("lista vacia\n");
  }else{
 if (x > index && x <= MAX) {
   for (int i = 0; i < index; i++) {
    if (x==lista[i]) return i;
   }
  }
}
}
//recuperar un elemento
int recuperar_elemento(int x){

if(estado_lista() == 0){
  printf("lista vacia\n");
  }else{
 if (x > index && x <= MAX) {
  printf("%d\n", lista[x]);
  }
}
}

//Insertar

void insertar_inicio(int x){
	int aux=0;
	if(estado_lista()==0){
		lista[0]=x;
		index++;
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
		index++;
		return;
	}
}

void insertar_final(int x){
	if (estado_lista()==-1){
		printf("Lista llena\n");
		index++;
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
	if(estado_lista()==0){
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
	if (estado_lista()== 0){
		printf("Lista Vacia\n");
		return;
	}
	else{
		for (int i =0; i<index; i++){
			for(int j = i+1; j<index; j++){
				if (lista[i]==lista[j]){
					for(int k = j+1; k< index; k++){
						index--;
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
  for(int i=0; i<index-1;i++)
    printf("%d\n", lista[i]);
  }
}






};
