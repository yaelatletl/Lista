#include<queue>
#include<list>
#include<stack>
#include <cstdlib>
#include <iostream>
using namespace std;
class Arista;
class Nodo{
	
	Nodo *sig;
	Arista *ady;
	bool visto;
	int id;
	friend class Grafo;
	
};

class Arista{
	
	Arista *sig;
	Nodo *ady;
	int peso;
	friend class Grafo;
	
};

class Grafo{
	
	Nodo *raiz;
	public:
		void inicializar();
		bool vacio();
		int  longitudg();
		Nodo *getnodo(int id);
		void InsertarArista(Nodo*origen,Nodo*destino,int peso);
		void InsertaNodo(int ID);
		void ListaAdyacencia();
		void EliminarArista(Nodo*origen,Nodo*destino);
		void menu();
		void EliminarNodo(Nodo*nodo);
		void Adyacencia(Nodo*origen,Nodo*destino);
		void RecorridoAnchura(Nodo *origen);
		void RecorridoProfundidad(Nodo *origen);
		
	
};
