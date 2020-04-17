#include "grafos.h"
//alguno


class ArbolBinario: public NodoGrafo{
public:
  int altura;
  bool primera_menor_a_id = false;

  void sumar_peso(){
  	Arbol *temp;
  	temp = this;
  	while(temp!=NULL){
  		temp->grado += 1;
  		temp = temp->anterior;
	  }
  	temp = anterior
  }
  ArbolBinario *obtener_padre(){
  return (ArbolBinario *)anterior;
  }
  void mostrar_hijos(char id, int *bandera){
    ArbolBinario *id1,*id2;
    temp = obtener_nodo(id);
    id2 = obtener_nodo_adyacente(1, bandera);
    id1 = obtener_nodo_adyacente(0,bandera);
    if (id1!=NULL){
      printf("Hijo 1 = %c\n", id1->id);
      if(id2!=NULL){
        printf("Hijo 2 = %c\n",id2->id);
      }
      else printf("No hay segundo hijo\n");
    }
    else{
    printf("No hay hijos para este nodo\n");
    }
  }

  void agregar_nodo(char id, int *bandera){
  	Arbol *temp = *obtener_nodo_adyacente(0, bandera); //Obtiene el primer nodo o NULL (izquierdo)
  	if(temp!=NULL){
  		if (temp->id<id){ //Si la id del primer nodo es menor, activa la bandera
  			primera_menor_a_id = true;
		  }

		  temp = obtener_nodo_adyacente(1, bandera); //Obtiene el segundo nodo o NULL (derecho)

		  if(temp!=NULL) { //Si el segundo nodo existe, entonces el arbol esta lleno
  			*bandera = 1;
  			return;
		  }

		else{ //Si la id a ingresar es menor a la ya ingresada, se agrega la arista al principio
			if(primera_menor_a_id){
				agregar_arista_inicio(this.id, id);
				temp = (ArbolBinario*)obtener_nodo_adyacente(0, bandera);
				temp->anterior = this;
			}	//En caso contrario se ingresa al final
			else {
				agregar_arista_final(this.id, id);
				temp = (ArbolBinario*)obtener_nodo_adyacente(1, bandera);
				temp->anterior = this;
			}
		}


	  }
	  else {
	  agregar_arista_final(this.id, id); //Si el arbol est� vacio no hace comprobaciones
  	temp = (Arbol*)obtener_nodo_adyacente(0, bandera);
  	temp->anterior = this;
	  }
  }


  void enlazar_origen_anterior(int *bandera){
    Nodo *temp;
    if(lista_vacia(bandera)) return;
    temp = Lista;
    do{
      printf("%c-->%c\n", ((Enlace*)(temp->dato))->origen->id, ((Enlace*)(temp->dato))->destino->id);
      ((NodoGrafo*)(((Enlace*)(temp->dato))->destino))->mostrar_elementos(bandera);
      temp = temp->sig;
      }while(temp!=NULL);
  }


  Arbol *obtener_hijo(int pos, int *bandera){
    return (Arbol*)recuperar_elemento(pos, bandera);
  }
  bool esta_lleno();
  void posorden(Arbol nodo){
    if (nodo==NULL) return;
    posorden(*(nodo.obtener_hijo(0,bandera)); //hijo1
    posorden(*(nodo.obtener_hijo(1, bandera))); //hijo2
    printf("Nodo %c\n", nodo.id);
  }
  void preorden(Arbol nodo){
    if (nodo==NULL) return;
    printf("Nodo %c\n", nodo.id);
    preorden(*(nodo.obtener_hijo(0, bandera))); //hijo1
    preorden(*(nodo.obtener_hijo(1, bandera))); //hijo2

  void inorden(Arbol nodo){
    if (nodo==null) return;
    preorden(*(nodo.obtener_hijo(0, bandera))); //hijo1
    printf("Nodo %c\n", nodo.id);
    preorden(*(nodo.obtener_hijo(1, bandera))); //hijo2
  }

  }
}
