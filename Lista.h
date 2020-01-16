/* Lista.h*/
#include <stdio.h>

class Lista{
protected:

int Max=50;
int lista[Max];
int x;


public:
  
int recurperar_sucesor(){
//recuperar sucesor
cin >> x;
if (x+1 > index) {
  cout << lista[x+1];
  }
}
int recuperar_elemento(){
//recuperar un elemento
cin >> x;
if (x > index) {
  cout << lista[x];
}
}

}
