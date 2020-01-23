#include <stdio.h>
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
int x, opc=0;	
Lista lista;
do{

printf("Ingrese la accion a realizar sobre la lista:\n 1)Insercion al inicio\n 2)insercion al final\n 3)suprimir al inicio\n 4)suprimir al final\n 5)eliminar repetidos\n 6)encotrar x\n 7)recuperar primero\n 8)recuperar ultimo\n 9)recuperar sucesor\n 10) recuperar predecesor\n 11)Mostrar lista\n 12)salir  \n");
scanf("%d", &opc);
//lista de opciones
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
	printf("Dame una posicion a buscar\n");
	scanf("%d", &x);
	
	printf("El elemento de la posicion %d es %d \n", x, lista.recuperar_elemento(x));
	getchar();
	break;
}
case 7: {
	printf("El elemento de la posicion inicial es %d \n", lista.recuperar_primero() );
	break;
} 
case 8: {
	printf("El elemento de la posicion inicial es %d \n", lista.recuperar_ultimo() );
	break;
}
case 9: {
	printf("El sucesor de la posicion %d es %d \n", x, lista.recuperar_sucesor(x));
	break;
}
case 10: {
	printf("El sucesor de la posicion %d es %d \n", x, lista.recuperar_predecesor(x));
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

}while(opc!=12); //Fin de do while
return 0;
}

