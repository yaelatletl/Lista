#include <stdio.h>
#include<stdlib.h>      //librerias.
#define Max 100
using namespace std;

void menu();

//matriz de adyacencia
int MatrizAdyacente[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
//TODO: Reemplazar la matriz por una lista ligada de acceso con polinomio de direccionamiento 

class nodoa { //creamos una clase y le damos como nombre nodoa.
   public: //creamos nuestro acceso p�blico.
// para que cualquier miembro del nodo accesible desde cualquier parte del progrma.
   	
    int ady;
    int peso;  //nombramos variables enteras.
    nodoa *siguiente; //creamos un puntero.
    nodoa(int v,int p, nodoa *sig = NULL)
    {
       ady = v;
       peso=p;        //creamos un constructor para nuestro grafo.
       siguiente = sig;
    }
};


struct nodo { //creamos nuestro nodo principal.
   
   public: //creamos nuestro acceso 
   // para que cualquier miembro del nodo accesible desde cualquier parte del progrma.
    int vertice; //creamos una varible entera.
    nodoa *puntero; //creamos un nuevo puntero utilizando la clase anteriormente creada
    nodo *siguiente; //creamos un nuevo puntero
    nodo(int v, nodo *sig = NULL,nodoa *punt=NULL) 
    {
       vertice = v;
       siguiente = sig;   //creamos un primer nodo constructor.
	   puntero=punt;
    }
  
    class lista; //creamos una clase lista
};

typedef nodo *pnodo; //creamos un nuevo puntero.

class lista {      
   public:	  //creamos nuestro acceso p�biclo 
   // para que cualquier miembro del nodo accesible desde cualquier parte del progrma.
    pnodo primero;  //creamos un nuevo puntero de tipo pnodo
    
	lista() { primero =  NULL; }// crea la lista vacia
	

void creararco(int i,int f,int peso, int* bandera){ //funci�n para crear un nuevo arco
	pnodo pos; // creamos un nuevo puntero
	pos=primero;	
	if(listavexiste(i,f, bandera)){
	while(pos!=NULL){ // se recorre la lista  hasta encontrar el valor buscado
		if(i == pos->vertice ){
			
			if(pos->puntero==NULL){	//sentencia if para verificar
				pos->puntero=new nodoa(f,peso); //creamos un nuevo constructor
			}
			else {
				nodoa *temp=pos->puntero; //creamos un nuevo puntero y lo igualamos
					while(temp->siguiente!=NULL){ //ciclo mientras
						temp=temp->siguiente; //guardamos los datos.
					}
					temp->siguiente=new nodoa(f,peso); //creamos un nuevo constructor
					temp=NULL; //lo igualamos a NULL
					delete temp; //eliminamos el 
				}
				}	
			pos=pos->siguiente;//guerdamos los datos.
			}
	}

//terminamos nuestra funci�n para crear los arcos  de nuestro grafo.

}

bool listavexiste(int i,int f, int* bandera){ //funci�n booleana	
	if(Buscarv(i, bandera)!=NULL&&Buscarv(f, bandera)!=NULL){ //sentencia if.
	return true; //retornamos verdadero o 1
	}
	else{ //sino
	return false; //retornamos falso o 0.
	}
// funci�n para verificar si nuestro grafo tiene arcos.	
}

void Insertarv(int v){ //funci�n para insertar los datos a nuestro grafo
   pnodo  anterior;   //creamos un nuevo puntero
   if(lista_vacia()) // Si la lista est� vac�a 
   {
	  primero = new nodo(v, primero);   //creamos un nuevo nodo
   }else { if(v<=primero->vertice){ //si el valor a insertar es menor que el  
	      primero =new nodo(v, primero) ;            //se inserta el nodo antes del primer dato de la lista
		}else{ 	   
			//en caso contrario se busca el nodo que tenga un dato menor a valor 
			anterior = primero; // Avanzamos hasta que el siguiente tenga un valor mayor que valor 
			while((anterior->siguiente) && (anterior->siguiente->vertice<=v)){ 
				anterior = anterior->siguiente; }
			   // Creamos un nuevo nodo despu�s del nodo anterior, y cuyo siguiente
               // es el siguiente del anterior
			   anterior->siguiente = new nodo(v, anterior->siguiente);
			}  
			
//funci�n para insertar los datos a nuestro grafo
}
}

bool lista_vacia(){ //funci�n booleana.
	return primero == NULL; //verificamos si nuestro grafo esta vacio.
	//funci�n para verificar si nuestro grafo tiene vertices o nodos.
}

int CantidadVertices(){ //funci�n para contar nuestro vertices o nodos
    pnodo nodo=primero; //creamos un nuevo nodo y lo igualamos a otro.   
    int i=0;//creamo una nueva variable entera y la igualamos a 0
    while(nodo!=NULL){//ciclo mientras, si nuestro nodo es distinto de NULL
       i++;//le sumamos 1 a nuestra variable.
       nodo=nodo->siguiente;  //igualamos nuestro nodos, para poder sumar la cantidad de los mismos                
    }
    return i; //retornamos i.
}

int ExisteArco(int i,int f, int *bandera){//funci�n para poder realizar la matriz adyacente 
  pnodo nodo; //creamos un nuevo nodo.
  int a=1;//creamos una variable entera, y la inicializamos en 1
    nodo=Buscarv(i, bandera);//igualamos nuestro nodo a la funci�n buscar.
    if(nodo){ //sentencia if, utilizando el nodo creado.
         if(BuscarAdy(nodo,f)){ //sentencia if, llamamos a nuestra funci�n booleana.
		 return a; //retornamos a
		 }else{
		 return a=0; //retornamos a
		 }        
    }   
}

bool BuscarAdy(pnodo aux,int ad){ //funci�n booleana para poder realizar la matriz adyacente
     nodoa *temp=aux->puntero; //creamos un nuevo puntero.
     bool a;  //creamos un varible de tipo boolena.
     while(temp){ //ciclo while o mientras.
        if(ad==temp->ady){ //sentencia if.
           return a=true;} //retornamos a verdadero.
        temp=temp->siguiente;//igualamos nuestro puntero para que verifique todos los valores.
     } 
	 return a=false;// sino retornamos a falso  
}

pnodo Buscarv(int valor, int* bandera){ //funci�n para buscar valores dentro de nuestro grafo
	int z;
	pnodo indice,n=NULL; //creamos un nuevo nodo e igualamos a la varible n a NULL
	indice=primero; //igualamos nuestro
	while(indice!=NULL){ // se recorre la lista  hasta encontrar el valor buscado
	if(valor == indice->vertice ){  
			return indice; // al encontar el valor  lo retorna
			}	
		indice=indice->siguiente; //igualamos nuestros nodos para que verifiquen nuestros datos
	}
    *bandera = 1;
 return n; // si el valor buscado no esta en la lista retorna nulo
}

void CrearMatriz(int* bandera){ //funci�n para crear nuestra matriz adyacente.
     pnodo nodo=primero,nodotemp; //creamos un nuevo puntero y lo igualamos.
     int i,j,inicio,fin; //creamos nuestras variables enteras.
     int cant=CantidadVertices(); //creamos un varibale entera y la igualamos a nuestra funci�n cantidad de vertices.
     for(i=0;i<cant;i++){ //ciclo for
         nodotemp=primero;//igualamos nuestros punteros.
       for(j=0;j<cant;j++){//ciclos for
       //guardamos en la matriz creada anteriormente los datos de nuestra funci�n existe arco.
         MatrizAdyacente[i][j]=ExisteArco(nodo->vertice,nodotemp->vertice, bandera);                                      
         nodotemp=nodotemp->siguiente; //igualamos nuestros punteros para que verifiquen todos los datos.
       }                
        nodo=nodo->siguiente;//igualamos nuestros punteros para que verifiquen todos los datos.
     }
     delete nodo; //eliminamos nodo  al terminar los ciclos for
     delete nodotemp;  //eliminamos nodotemp al terminar los ciclos for.
}

void mostrarmatriz(){ //funci�n para mostrar nuestra matriz adyacente.
    int i,j,cant; //creamos varibales enteras
    pnodo nodo=primero; //creamos un nuevo puntero.
    cant=CantidadVertices(); //igulamos  la varibale creada anteriormente a la cantidad de vertices.
	printf("   "); //espacios
	
    for(i=0;i<cant;i++){ //ciclo for.
	printf("\t %d ",nodo->vertice); //mostramos los nodos o vertices del grafo.
	nodo=nodo->siguiente; //igualamos los punteros para que muestre todos los vertices
	}
    nodo=primero; //igualamos los punteros
	printf("\n\n"); //saltos de linea.
	
    for( i=0;i<cant;i++){ //ciclo for.
    	
		 printf("%d", nodo->vertice); //mostramos los vertices de nuestro grafo.
         for(j=0;j<cant;j++){ //ciclo for
			printf("\t%d ",MatrizAdyacente[i][j]); //mostramos los datos guardados en la matriz.
         }
         nodo=nodo->siguiente; //igualamos los punteros para que muestre todos los datos.
         printf("\n"); //salto de linea.
    }     
}
};
int main(){ //funci�n principal.
menu();
return 0;//retornamos el control a nuestro sistema operativo.
}

void menu(){
	system("cls");
	int op1=0,valor=0, bandera=0; //creamos 2 varibles enteras.
	lista l; //creamos una nueva clase.
	   	l.Insertarv(1); 
		l.Insertarv(2);
		l.Insertarv(3);//creamos y asignamos valores a nuestros vertices o nodos
		l.Insertarv(4);
		l.Insertarv(5);
		l.creararco(1,2,1, bandera);
		l.creararco(2,1,1, bandera);
		l.creararco(1,4,2, bandera);
		l.creararco(4,1,2, bandera) ;
		l.creararco(4,3,3, bandera);
		l.creararco(3,4,3, bandera);
		l.creararco(3,2,4, bandera);
		l.creararco(2,3,4, bandera);
		l.creararco(4,5,5, bandera);
		l.creararco(5,4,5, bandera);
		l.creararco(5,2,6, bandera);
		l.creararco(2,5,6, bandera);
		
		cout<<"\n"; //salto de linea
	cout<<"\n\n\tGRAFO DIRIGIDO ALGORITMOS||UCN"; //mensaje
	cout<<"\n"; 
    cout<<"\n\n\t1. Mostrar Matriz Adyacente";  
    cout<<"\n\n\t2. Buscar"; 
    cout<<"\n\n\t3. Salir";
    cout<<"\n"; 
	cout<<"\n"; 
    cout<<"\nIngrese opcion: ";
	cin>>op1; 
switch(op1){
case 1:
	system("cls");
    cout<<"\n"; //salto de liena
  	cout<<"\n\n\tMATRIZ DE ADYACENCIA"<<"\n\n"; //mensaje
	l.CrearMatriz(); //llamamos a nuestra funci�n para que cree la matriz con los datos ingresados
	l.mostrarmatriz(); //mostramos la matriz adyacente.	
    cout<<"\n";
    cout<<"\n";
    system("pause");
    menu();
break;

case 2:
	system("cls");
	cout<<"\nIngrese numero que desea buscar: ";
	cin>>valor;
	l.Buscarv(valor); //funci�n para buscar valores en nuestro grafo
	cout<<"\n";
	cout<<"\n";
	system("pause");
	menu();
break;
case 3:
system("cls");
cout<<"\n";			
cout<<"\n\n\tUCN INGENIERIA INFORMATICA!"; //termina nuestro programa 
cout<<"\n";
return;	
break;
default: 
        system("cls");  
        cout<<"\n\n\tOPCION NO VALIDA"; //manejo de excepciones.
        cout<<"\n";	
        system("pause");
		menu();
		break;
}
}













