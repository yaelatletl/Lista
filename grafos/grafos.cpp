/*  GRAFO
Angel Sanchez Cabrera
Yael Atletl Bueno Rojas	
Leonardo Emmanuel Perez Ocampo
Roberto Aguirre Coyotzi
*/

#include <stdio.h>
#include<stdlib.h>      //librerias.
#define Max 100
using namespace std;

void menu();//prototipo de funcion menu

//matriz de adyacencia
int MatrizAdyacente[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
//TODO: Reemplazar la matriz por una lista ligada de acceso con polinomio de direccionamiento 
int M_cuadrada[Max][Max];
int M_cubica[Max][Max];

class nodoa { //creamos una clase y le damos como nombre nodoa.
   public: //creamos nuestro acceso público.
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
   public:	  //creamos nuestro acceso púbiclo 
   // para que cualquier miembro del nodo accesible desde cualquier parte del progrma.
    pnodo primero;  //creamos un nuevo puntero de tipo pnodo
    
	lista() { primero =  NULL; }// crea la lista vacia
	

void creararco(int i,int f,int peso, int* bandera){ //función para crear un nuevo arco
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

//terminamos nuestra función para crear los arcos  de nuestro grafo.

}

bool listavexiste(int i,int f, int* bandera){ //función booleana	
	if(Buscarv(i, bandera)!=NULL&&Buscarv(f, bandera)!=NULL){ //sentencia if.
	return true; //retornamos verdadero o 1
	}
	else{ //sino
	return false; //retornamos falso o 0.
	}
// función para verificar si nuestro grafo tiene arcos.	
}

void Insertarv(int v){ //función para insertar los datos a nuestro grafo
   pnodo  anterior;   //creamos un nuevo puntero
   if(lista_vacia()) // Si la lista está vacía 
   {
	  primero = new nodo(v, primero);   //creamos un nuevo nodo
   }else { if(v<=primero->vertice){ //si el valor a insertar es menor que el  
	      primero =new nodo(v, primero) ;            //se inserta el nodo antes del primer dato de la lista
		}else{ 	   
			//en caso contrario se busca el nodo que tenga un dato menor a valor 
			anterior = primero; // Avanzamos hasta que el siguiente tenga un valor mayor que valor 
			while((anterior->siguiente) && (anterior->siguiente->vertice<=v)){ 
				anterior = anterior->siguiente; }
			   // Creamos un nuevo nodo después del nodo anterior, y cuyo siguiente
               // es el siguiente del anterior
			   anterior->siguiente = new nodo(v, anterior->siguiente);
			}  
			
//función para insertar los datos a nuestro grafo
}
}

bool lista_vacia(){ //función booleana.
	return primero == NULL; //verificamos si nuestro grafo esta vacio.
	//función para verificar si nuestro grafo tiene vertices o nodos.
}

int CantidadVertices(){ //función para contar nuestro vertices o nodos
    pnodo nodo=primero; //creamos un nuevo nodo y lo igualamos a otro.   
    int i=0;//creamo una nueva variable entera y la igualamos a 0
    while(nodo!=NULL){//ciclo mientras, si nuestro nodo es distinto de NULL
       i++;//le sumamos 1 a nuestra variable.
       nodo=nodo->siguiente;  //igualamos nuestro nodos, para poder sumar la cantidad de los mismos                
    }
    return i; //retornamos i.
}

int ExisteArco(int i,int f, int *bandera){//función para poder realizar la matriz adyacente 
  pnodo nodo; //creamos un nuevo nodo.
  int a=1;//creamos una variable entera, y la inicializamos en 1
    nodo=Buscarv(i, bandera);//igualamos nuestro nodo a la función buscar.
    if(nodo){ //sentencia if, utilizando el nodo creado.
         if(BuscarAdy(nodo,f)){ //sentencia if, llamamos a nuestra función booleana.
		 return a; //retornamos a
		 }else{
		 return a=0; //retornamos a
		 }        
    }   
}

bool BuscarAdy(pnodo aux,int ad){ //función booleana para poder realizar la matriz adyacente
     nodoa *temp=aux->puntero; //creamos un nuevo puntero.
     bool a;  //creamos un varible de tipo boolena.
     while(temp){ //ciclo while o mientras.
        if(ad==temp->ady){ //sentencia if.
           return a=true;} //retornamos a verdadero.
        temp=temp->siguiente;//igualamos nuestro puntero para que verifique todos los valores.
     } 
	 return a=false;// sino retornamos a falso  
}


pnodo Buscarv(int valor, int* bandera){ //función para buscar valores dentro de nuestro grafo
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


void CrearMatriz(int* bandera){ //función para crear nuestra matriz adyacente.
     pnodo nodo=primero,nodotemp; //creamos un nuevo puntero y lo igualamos.
     int i,j,inicio,fin; //creamos nuestras variables enteras.
     int cant=CantidadVertices(); //creamos un varibale entera y la igualamos a nuestra función cantidad de vertices.
     for(i=0;i<cant;i++){ //ciclo for
         nodotemp=primero;//igualamos nuestros punteros.
       for(j=0;j<cant;j++){//ciclos for
       //guardamos en la matriz creada anteriormente los datos de nuestra función existe arco.
         MatrizAdyacente[i][j]=ExisteArco(nodo->vertice,nodotemp->vertice, bandera);                                      
         nodotemp=nodotemp->siguiente; //igualamos nuestros punteros para que verifiquen todos los datos.
       }                
        nodo=nodo->siguiente;//igualamos nuestros punteros para que verifiquen todos los datos.
     }
     delete nodo; //eliminamos nodo  al terminar los ciclos for
     delete nodotemp;  //eliminamos nodotemp al terminar los ciclos for.
}

void mostrarmatriz(int op){ //función para mostrar nuestra matriz adyacente.
    int i,j,cant; //creamos varibales enteras
    pnodo nodo=primero; //creamos un nuevo puntero.
    cant=CantidadVertices(); //igulamos  la varibale creada anteriormente a la cantidad de vertices.
    if(op==3){
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
    	
	}else if(op==6){
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
			printf("\t%d ",M_cuadrada[i][j]); //mostramos los datos guardados en la matriz.
         }
         nodo=nodo->siguiente; //igualamos los punteros para que muestre todos los datos.
         printf("\n"); //salto de linea.
    }  
		
	}else{
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
			printf("\t%d ",M_cubica[i][j]); //mostramos los datos guardados en la matriz.
         }
         nodo=nodo->siguiente; //igualamos los punteros para que muestre todos los datos.
         printf("\n"); //salto de linea.
    }  
	}
	  
}

void crearMcuadrada(){
	int i,j,k,cant;
	cant=CantidadVertices();
	for(i=0;i<cant;i++){
		
		for(j=0;j<cant;j++){
				M_cuadrada[i][j]=0;
			for(k=0;k<cant;k++){
				
				M_cuadrada[i][j]+=MatrizAdyacente[i][k]*MatrizAdyacente[k][j];
			}
			
		}
	}
	
}

void crearMcubica(){
	int i,j,k,cant;
	cant=CantidadVertices();
	crearMcuadrada();
	for(i=0;i<cant;i++){
		
		for(j=0;j<cant;j++){
			M_cubica[i][j]=0;
			for(k=0;k<cant;k++){
				
				M_cubica[i][j]+=M_cuadrada[i][k]*MatrizAdyacente[k][j];
			}
			
		}
	}
	
}

};
int main(){ //función principal.
int op1=0,valor=0, bandera=0,x=0,y=0,peso=0; //creamos 2 varibles enteras y una bandera para manejar las excepciones.
lista l; //creamos una nueva clase.
do{
menu();
  printf("\nIngrese opcion: ");
	scanf("%d", &op1); 
	
	switch(op1){
		
		case 1:
			printf("\ningrese el valor(id) del vertice : ");
			scanf("%d", &x); 
			l.Insertarv(x); //creamos y asignamos valores a nuestros vertices o nodos
			break;
			
		case 2:
			printf("\n\n!!Creacion de ARISTA!!\n");
			printf("\ningrese el valor (id) del vertice predecesor : ");
			scanf("%d", &x);												//creamos los arcos entre los vertices
				printf("\ningrese el valor (id) del vertice sucesor : ");
			scanf("%d", &y);
				printf("\ningrese el peso de la arista : ");
			scanf("%d", &peso);
			l.creararco(x,y,peso,&bandera);
			break;
			
		case 3:
			 printf("\n");// salto ce linea
    printf("\n");
			printf("\n\n\tMATRIZ DE ADYACENCIA\n\n"); //mensaje
				l.CrearMatriz(&bandera); //llamamos a nuestra función para que cree la matriz con los datos ingresados
				l.mostrarmatriz(op1); //mostramos la matriz adyacente.	
				
				 printf("\n");
    printf("\n");
    
    			break;//fin de caso
    			
    			
    	case 4:
    		printf("\n\n!!Cardinalidad!!\n"); //se muestra la cantidad de vertices que hay en el Grafo
    		printf("\nLa cardinalidad de los vertices es : ",l.CantidadVertices());
			break;
			
			
		case 5:
			printf("\n\nComprobar si exite un arco entre dos vertices\n");
				printf("ingrese el valor (id) del vertice predecesor : ");
			scanf("%d", &x);												//verificamos la relacion entre dos vertices
				printf("ingrese el valor (id) del vertice sucesor : ");
			scanf("%d", &y);
			if(l.ExisteArco(x,y,&bandera)==1){
				printf("\nExiste un arco entre el vertice",x,"y el vertice",y);
			}else{
				printf("\nNO existe un arco entre el vertice",x,"y el vertice",y);
			}
			break;
			
			
		case 6:
					 printf("\n");// salto ce linea
    printf("\n");
			printf("\n\n\tMATRIZ DE ADYACENCIA CUADRDA\n\n"); //mensaje
				l.crearMcuadrada(); //llamamos a nuestra función para que cree la matriz con los datos ingresados
				l.mostrarmatriz(op1); //mostramos la matriz adyacente.	
				
				 printf("\n");
    printf("\n");
    
    			break;//fin de caso
    			
    			
    	case 7:
    						 printf("\n");// salto ce linea
    printf("\n");
			printf("\n\n\tMATRIZ DE ADYACENCIA CUBICA\n\n"); //mensaje
				l.crearMcubica(); //llamamos a nuestra función para que cree la matriz con los datos ingresados
				l.mostrarmatriz(op1); //mostramos la matriz adyacente.	
				
				 printf("\n");
    printf("\n");
    
    			break;//fin de caso
			
			
		case 0:
			printf("\n\n \t°°°°°° ADIOS°°°°°\n\n");
			break;
			
			
			
			default:
				printf("\n\nOpcion NO valida!!!!!!!!"); //caso especial  de no encontrar la opcion digitada
				break;
			
	}

	
}while(op1!=0);// ciclo centinela



return 0;//retornamos el control a nuestro sistema operativo.
}

void menu(){ //funcion menu

		
		printf("\n"); //salto de linea
	printf("\n\n\tMENU DE GRAFOS"); //menu
	printf("\n"); 
    printf("\n\n\t1. Insertar vertices al Grafo");  
    printf("\n\n\t2. Crear Aristas"); 
    printf("\n\n\t3. Matriz de Adyacencia");
    printf("\n\n\t4. Cardinalidad del Grafo");
    printf("\n\n\t5. Comprobar arco entre nodos Dirigidos");
    printf("\n\n\t6. M^2"); 
    printf("\n\n\t7. M^3"); 
    printf("\n\n\t0. Salir");
    printf("\n"); 
	printf("\n"); 

}













