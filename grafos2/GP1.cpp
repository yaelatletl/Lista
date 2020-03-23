#include<stdio.h>
#include"GP1.h"

void Grafo :: inicializar(){
	
	raiz=NULL;
}

bool Grafo::vacio(){
	if(raiz==NULL){
		printf("\n EL GRAFO ESTA VACIO \n");	
		return true;
	}
	
	return false ;
}
int Grafo::longitudg(){
	int cont=0;
	Nodo *aux;
	aux=raiz;
	while(aux!=NULL){
		cont++;
		aux=aux->sig;
	}
	return cont;
}

Nodo *Grafo::getnodo(int identificador){
	Nodo *aux;
	aux=raiz;
	while(aux!=NULL){
		if(aux->id==identificador){
			return aux;
		}
		aux=aux->sig;
	}
	printf("\n No existe el nodo \n");
	return NULL;
	
}
void Grafo::InsertaNodo(int ID){
	Nodo *nuevo=new Nodo;
	nuevo->id=ID;
	nuevo->sig=NULL;
	nuevo->ady=NULL;
	if(vacio()){
		raiz=nuevo;
	}else{
			Nodo *aux;
	aux=raiz;
	while(aux->sig!=NULL){
		
		aux=aux->sig;
	}
	aux->sig=nuevo;
	}
}

void Grafo::InsertarArista(Nodo*origen,Nodo*destino,int peso){
	
	Arista *relacion =new Arista;
	relacion->peso=peso;
	relacion->sig=NULL;
	relacion->ady=NULL;
	Arista *aux;
	aux=origen->ady;
	if(aux==NULL){
		origen->ady=relacion;
		relacion->ady=destino;
	}else{
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=relacion;
		relacion->ady=destino;
	}
	
}

void Grafo::ListaAdyacencia(){
		if(vacio()){
		printf("\n\n NO se puede imprimir nada si no hay nodos primero\n\n");
	}else{
	Nodo *auxG;
	Arista *auxADY;
	
	auxG = raiz;
	while(auxG!=NULL){
		
		printf("%d ->",auxG->id);
		auxADY=auxG->ady;
		while(auxADY!=NULL){
			printf("%d ->",auxADY->ady->id);
			auxADY=auxADY->sig;
		}
		printf("\n");
		auxG=auxG->sig;
	}
}
}

void Grafo::EliminarArista(Nodo*origen,Nodo*destino){
		if(vacio()){
		printf("\n\n No se pueden eliminar aristas si no hay nodos \n\n");
	}else{
	Arista *actual, *ante;
	
	actual=origen->ady;
	if(actual==NULL){
		printf("\nNO hay nodos de adyacencia \n");
	}else if(actual->ady==destino){
		origen->ady=actual->sig;
		delete(actual);
	}else{
		while(actual->ady!=destino&&actual!=NULL){
			ante=actual;
			actual=actual->sig;
		}
		if(actual==NULL){
			printf("\n NO existe adyacencia alguna entre el oriegen y destino\n");
		}else if(actual->sig!=NULL){
			ante->sig=actual->sig;
			delete(actual);
		}else{
			ante->sig=NULL;
			delete(actual);
		}
	}
}
}
void Grafo::menu(){
	printf("\t\t\t\n\n같같같같 MENU 같같같같�\n\n");
	printf("\t\n 1.- Longitud del Grafo\n");
	printf("\t\n 2.- Insertar Nodo\n");
	printf("\t\n 3.- Lista de adyacencia\n");
	printf("\t\n 4.- Eliminar adyacencia\n");
	printf("\t\n 5.- Crear adyacencia\n");
	printf("\t\n 6.- Eliminar Nodo\n");
	printf("\t\n 7.- Adyacencia\n");
	printf("\t\n 8.- Recorrido a lo Ancho\n");
	printf("\t\n 9.- Recorrido en Profundidad\n");
	printf("\t\n 0.- Salir\n");
	printf("\t\n ingresa la opcion que quieres : ");
	
}
void Grafo::EliminarNodo(Nodo*nodo){
		if(vacio()){
		printf("\n\n NO hay nodos que eliminar\n\n");
	}else{
		Nodo *actualG,*anteG;
	Arista *auxADY;
	
	actualG = raiz;
	while(actualG!=NULL){
		
		
		auxADY=actualG->ady;
		while(auxADY!=NULL){
			if(auxADY->ady==nodo){
				EliminarArista(actualG,auxADY->ady);
				break;
			}
			
			auxADY=auxADY->sig;
		}
		
		actualG=actualG->sig;
	}
	
	actualG=raiz;
	 if(raiz==nodo){
	 	raiz=raiz->sig;
	 	delete(actualG);
	 }else {
	 		while(actualG!=nodo&&actualG!=NULL){
			anteG=actualG;
			actualG=actualG->sig;
		}	
		if(actualG==NULL){
			printf("\n NO existe el nodo que quieres eliminar\n");
		}else if(actualG->sig!=NULL){
			anteG->sig=actualG->sig;
			delete(actualG);
		}else{
			anteG->sig=NULL;
			delete(actualG);
		}
	 	
	 }
}
	
}

void Grafo::Adyacencia(Nodo*origen,Nodo*destino){
		if(vacio()){
		printf("\n\n Ni si quiera hay nodos como para determinar la adyacencia \n\n");
	}else{
	Arista *aux;
	aux=origen->ady;
	while(aux!=NULL){
		if(aux->ady==destino){
			printf("\n\n Si EXISTE una arista entre el nodo %d y el nodo %d",origen->id,destino->id);
			break;
		}
		aux=aux->sig;
	}
	if(aux==NULL){
		printf("\n\n NO EXISTE una arista entre el nodo %d y el nodo %d",origen->id,destino->id);
	}
}
}

void Grafo::RecorridoAnchura(Nodo*origen){
	if(vacio()){
		printf("\n\n ya que esta vacio no se puede realizar el recorrido\n\n");
	}else{
		
	
	Nodo *actual;
	int flag,flag1;
	queue<Nodo*> cola;
	list<Nodo*> lista;
	list<Nodo*> :: iterator i;
	cola.push(origen);
	while(!cola.empty()){
		flag=0;
		actual=cola.front();
		cola.pop();
		for(i=lista.begin();i!=lista.end();i++){
			if(*i==actual){
				flag=1;
			}
		}
		
		if(flag==0){
			printf("%d ,",actual->id);
			lista.push_back(actual);
			
			Arista *aux;
			aux=actual->ady;
			
			while(aux!=NULL){
				flag1=0;
				
					for(i=lista.begin();i!=lista.end();i++){
						
						if(aux->ady==*i){
							flag1=1;
						}
						
					}
					
				if(flag1==0){
					cola.push(aux->ady);
				}
				aux=aux->sig;
			}
		}
	}
}
}

void Grafo::RecorridoProfundidad(Nodo *origen){
		if(vacio()){
		printf("\n\n ya que esta vacio no se puede realizar el recorrido\n\n");
	}else{
			Nodo *actual;
			int flag,flag1;
			stack<Nodo*> pila;
			list<Nodo*> lista;
			list<Nodo*> :: iterator i;
			pila.push(origen);
			
			while(!pila.empty()){
				flag=0;
				actual=pila.top();
				pila.pop();
				for(i=lista.begin();i!=lista.end();i++){
					
					if(*i==actual){
						flag=1;
					}
				}
				
				if(flag==0){
					printf("%d ,",actual->id);
					lista.push_back(actual);
					Arista *aux;
					aux=actual->ady;
					
					while(aux!=NULL){
						flag1=0;
						for(i=lista.begin();i!=lista.end();i++){
							if(*i==aux->ady){
								flag1=1;
							}
						}
						if(flag1==0){
							pila.push(aux->ady);
						}
						aux=aux->sig;
					}
				}
				
			}
		
		
	}
	
	
}


