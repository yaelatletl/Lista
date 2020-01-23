#include <stdio.h>
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Lista{
	private :
		#difine Max 50;
		int array[Max];
		
	public:
		Lista(int arreglo); //constructor 
		void insercion(int arreglo, int elemento);
		void suprimir(int arreglo );
		void eliminar_los_elementos_duplicados();
		int recuperar_un_elemento(int elemento);
		int recuperar_sucesor();
		int recuperar_predecesor();
};

int main(int argc, char** argv) {
	Lista lista;
	printf("Ingrese la accion a realizar sobre la lista\n");
	return 0;
	
	//dentro de qui haremos todas las funciones ?
	
}
