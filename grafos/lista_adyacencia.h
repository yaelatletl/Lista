#include "Lista_doble_ligada.h"



class ListaAdyacencia: public ListaDoble{
	protected:
		int bandera=0;
	public:
		void agregar_lista(void* nodo){
			insertar_final(nodo, &bandera);
		}
		
			
};
