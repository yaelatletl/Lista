/* Lista.h*/
#include <stdio.h>

class Lista{
protected:

int Max=50;
int lista[Max];
int x;
int index;

public:
//recuperar sucesor  
int recurperar_sucesor(){

if(Lista == 0){
  cout << "lista vacia";
}else {
  cin >> x;
  if (x+1 > index) {
   cout << lista[x+1];
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
  cout << "lista vacia";
  }else{
 cin >> x;
 if (x > index) {
  cout << lista[x];
  }
}

}

