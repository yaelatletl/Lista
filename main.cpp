#include <stdio.h>
#include "Lista.h"
#include "Cola.h"
#include "Pila.h"

void Listas(Lista lista, int opc){
	int y;
	switch(opc) {
	case 1: {
		printf("Dame un numero a insertar\n");
		scanf("%d", &x);

		lista.insertar_inicio(x);
		getchar();
		break;
	}

	case 2:{
		printf("Dame un numero a insertar\n");
		scanf("%d", &x);

		lista.insertar_final(x);
		getchar();
		break;
	}
	case 3:{
		x = lista.suprimir_primero();
		if (x!=-1) printf("Se ha eliminado el numero %d \n", x );
		break;
	}

	case 4:{
		x = lista.suprimir_ultimo();
		if(x!=-1) printf("Se ha eliminado el numero %d \n", x );
		break;
	}
	case 5: {
		lista.eliminar_duplicados();
		break;
	}

	case 6:
	{
		printf("Dame un numero a buscar\n");
		scanf("%d", &x);
		y = lista.recuperar_pos_elemento(x);
		if (y == -1) printf("Elemento no encontrado\n");
		else	printf("La posicion del elemento %d es %d \n", x, y);
		getchar();
		break;
	}
	case 7: {
		printf("El elemento de la posicion inicial es %d \n", lista.recuperar_primero() );
		break;
	}
	case 8: {
		printf("El elemento de la posicion final es %d \n", lista.recuperar_ultimo() );
		break;
	}
	case 9: {
		printf("Dame un numero a buscar\n");
		scanf("%d", &x);
		printf("El sucesor del numero %d es %d \n", x, lista.recuperar_sucesor(x));
		getchar();
		break;
	}
	case 10: {
		printf("Dame un numero a buscar\n");
		scanf("%d", &x);
		printf("El predecesor del numero %d es %d \n", x, lista.recuperar_predecesor(x));
		getchar();
		break;
	}
	case 11:{
		lista.mostrar_elementos();
		break;
	}

	default:{
		printf("numero invalido\n");
		break;
	}

	} //Fin de switch
}

void Colas(Colas cola, int x){
	int y;
	switch (x) {
		case 1:{
			printf("Dame el numero a ingresar\n");
			scanf("%d", &y);
			cola.encolar(y);
			getchar();
			break;
		}
		case 2:{
			printf("El numero que se desencoló es %d\n", cola.desencolar());
			break;
		}

		case 3:{
			printf("Dame el numero a buscar\n");
			scanf("%d", &y);
			y = cola.recuperar();
			if(y == -1) printf("Numero no encontrado\n");
			else	printf("La posicion del numero %d es\n", y);
			getchar();
			break;
		}

	}
}

void Pilas(Pila pila, int x){
	int y;
	switch (x) {
		case 1:{
			printf("Dame el numero a ingresar\n");
			scanf("%d", &y);
			pila.push(y);
			getchar();
		break;
		}
		case 2:{
			printf("Se popeó %d\n", pila.pop());
		}
	}
}

int main(int argc, char** argv) {
int x, opc=0;
Lista lista;
Cola cola;
Pila pila;
do {
	printf("Ingrese donde quiere realizar operaciones \n1.- Lista\n2.- Cola\n3.- Pila");
	scanf("%d", &opc);
	switch (opc) {
		case 1:{
			printf("Ingrese la accion a realizar sobre la lista:\n 1)Insercion al inicio\n 2)insercion al final\n 3)suprimir al inicio\n 4)suprimir al final\n 5)eliminar repetidos\n 6)encotrar x\n 7)recuperar primero\n 8)recuperar ultimo\n 9)recuperar sucesor\n 10) recuperar predecesor\n 11)Mostrar lista\n 12)salir  \n");
			scanf("%d", &opc);
			Listas(opc);
			break;
		}
		case 2:{
		printf("Ingrese la accion a realizar sobre la lista:\n 1)Insercion al inicio\n 2)insercion al final\n 3)suprimir al inicio\n 4)suprimir al final\n 5)eliminar repetidos\n 6)encotrar x\n 7)recuperar primero\n 8)recuperar ultimo\n 9)recuperar sucesor\n 10) recuperar predecesor\n 11)Mostrar lista\n 12)salir  \n");
		scanf("%d", &opc);
		Colas(opc);
		break;}
		case 3:{
		printf("Ingrese la accion a realizar sobre la lista:\n 1)Insercion al inicio\n 2)insercion al final\n 3)suprimir al inicio\n 4)suprimir al final\n 5)eliminar repetidos\n 6)encotrar x\n 7)recuperar primero\n 8)recuperar ultimo\n 9)recuperar sucesor\n 10) recuperar predecesor\n 11)Mostrar lista\n 12)salir  \n");
		scanf("%d", &opc);
		Pilas(opc);
		break;}
	}



//lista de opciones




} while(opc!=12);
return 0;
}
