/* Lista.h*/
#include <stdio.h>

class Lista{
protected:

int Max=50;
int lista[Max];
int x;
int index;

public:
  
int recurperar_sucesor(){
//recuperar sucesor
if(Lista == 0){
  cout << "lista vacia";
}else {
  cin >> x;
  if (x+1 > index) {
   cout << lista[x+1];
  }
}
  
int recuperar_elemento(){
//recuperar un elemento
if(Lista == 0){
  cout << "lista vacia";
  }else{
 cin >> x;
 if (x > index) {
  cout << lista[x];
  }
}

}

