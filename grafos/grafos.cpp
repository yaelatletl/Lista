/*  GRAFO
Angel Sanchez Cabrera
Yael Atletl Bueno Rojas	
Leonardo Emmanuel Perez Ocampo
Roberto Aguirre Coyotzi
*/

#include "grafos.h"
#include "lista_adyacencia.h"

 //creamos un nuevo puntero.

int main(){ //función principal.
int op1=0,valor=0, bandera=0,x=0,y=0,peso=0; //creamos 2 varibles enteras y una bandera para manejar las excepciones.
Grafo l; //creamos una nueva clase.
ListaAdyacencia Adyacencia;
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













