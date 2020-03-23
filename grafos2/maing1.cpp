#include<stdio.h>
#include"GP1.h"

int main(){
	Grafo G;
	int opc,x,y,z;
	
	G.inicializar();
	do{
	G.menu();
	scanf("%d",&opc);
	switch(opc){
		case 1:
			printf("\t\n La longitud del grafo es : %d\n",G.longitudg());
			break;
		case 2:
			printf("\t\n Ingrese un numero para identificar al nodo : \n");
			scanf("%d",&x);
			G.InsertaNodo(x);
			break;
		case 3:
			printf("\t\t\n\n °°°Lista de Adyacencia°°° \n");
			G.ListaAdyacencia();
			break;
		case 4:
			printf("\t\n ingrese el numero identificador del nodo origen : \n");
			scanf("%d",&x);
				printf("\t\n ingrese el numero identificador del nodo destino : \n");
				scanf("%d",&y);
				G.EliminarArista(G.getnodo(x),G.getnodo(y));
			break;
		case 5:
				printf("\t\n ingrese el numero identificador del nodo origen:  \n");
					scanf("%d",&x);
				printf("\t\n ingrese el numero identificador del nodo destino : \n");
				scanf("%d",&y);
					printf("\t\n ingrese el peso de la arista :  \n");
					scanf("%d",&z);
					G.InsertarArista(G.getnodo(x),G.getnodo(y),z);
				
			break;
		case 6:
				printf("\t\n ingrese el numero identificador del nodo que quiere eliminar :  \n");
					scanf("%d",&y);
			G.EliminarNodo(G.getnodo(y));
			
			break;
		case 7:
			printf("\t\n ingrese el numero identificador del nodo origen:  \n");
					scanf("%d",&x);
				printf("\t\n ingrese el numero identificador del nodo destino : \n");
				scanf("%d",&y);
				G.Adyacencia(G.getnodo(x),G.getnodo(y));
			break;
		case 8:
			printf("\t\n ingrese el numero identificador del nodo origen en donde comenzara el recorrido:  \n");
					scanf("%d",&x);
					G.RecorridoAnchura(G.getnodo(x));
			break;
		case 9:
			printf("\t\n ingrese el numero identificador del nodo origen en donde comenzara el recorrido:  \n");
					scanf("%d",&x);
					G.RecorridoProfundidad(G.getnodo(x));
			break;
			case 0:
				printf("\t\n °°°°° adios °°°°°°°\n");
				break;
				default:
					printf("\t\n Opcion no valida , ingrese otro numero\n");
					break;
	}
		
	}while(opc!=0);
	
	
}
