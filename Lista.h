/* Lista.h*/
#include <stdio.h>

class Lista{
protected:

int Max=50,x,i,index;
int lista[Max];


public:
//recuperar primero
int recurperar_primero(){

if(Lista == 0){
  cout << "lista vacia";
}else {
  cout << lista[0];
 }
}

//recuperar ultimo
int recurperar_utlimo(){

if(Lista == 0){
  printf("lista vacia\n");
}else {
  printf("%d", lista[index-1]);
  }
}

//recuperar sucesor
int recurperar_sucesor(){

if(Lista == 0){
  printf("lista vacia\n");
  return -1;
}else {
  scanf("%d",x);
  if (x+1 > index) {
   printf("%d\n", lista[x+1]);
  }
}

//recuperar predecesor
int recurperar_predecesor(){

if(Lista == 0){
  cout << "lista vacia";
}else {
  cin >> x;
  if (0 > x > index) {
   cout << lista[x-1];
  }
}

//recuperar un elemento
int recuperar_elemento(){

if(Lista == 0){
  printf("lista vacia\n");
  }else{
 scanf("%d", x);
 if (x > index) {
  printf("%d\n", lista[x]);
  }
}
//Mostrar lista
int recuperar_elemento(){
 
  if(Lista == 0){
  printf("lista vacia\n");
  }else{ 
  for(i=0;i>index;i++)
    printf(lista[i])
  }  
}
