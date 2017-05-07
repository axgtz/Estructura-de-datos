//Roberto Alejandro Gutiérrez Guillén		A01019608
#include <iostream>

//Librerias de lectura de datos
#include <fstream>
#include <sstream>

#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node {
	int data = NULL;
	Node *pointIzq = NULL;
	Node *pointDer = NULL;
};

class Arbol {
private:
	Node *raiz;
public:
	Arbol();
	// Crea el árbol leyendo los datos desde un archivo tipo texto
	void crear(string archivo);
	// Inserta un elemento en el árbol
	void insertar(int dato);
	// Buscar un elemento en el árbol. Regresa true si se encontró  
	// el dato y en lugar regresa un apuntador al nodo que lo contiene
	bool buscar(int dato, Node *&lugar);
	// Elimina un elemento dado del árbol. Regresa true si se pudo  
	// eliminar y false en caso contrario
	bool elimina(int dato);
	// Imprime todos los elementos del árbol binario en INORDEN.
	void imprime();
};
Arbol::Arbol() {}

void Arbol::crear(string archivo) {
	ifstream archivo_entrada; //Declarar variable que se usa para acceder a las funciones de ifstream

	string st = archivo + ".txt";

	archivo_entrada.open(st);

	if (archivo_entrada.fail()) {
		cout << "Error al abrir el archivo" << endl;
		return;
	}

	char linea[128];

	archivo_entrada.getline(linea, sizeof(linea));		//Usando la variable linea se extrae toda la primera linea del archivo de texto
	
	int tam;

	if (!(istringstream(linea) >> tam)) {				//Se guarda el numero de lineas que contiene el archivo de texto
		tam = 0;
		cout << "Error al leer el tamaño del arreglo en el archivo de texto" << endl;
	}
	//int *vec = new int[tam];

	//Agregar la raiz
	archivo_entrada.getline(linea, sizeof(linea));

	//Se crea el node con nombre nd
	Node * nd = new Node;
	//Se asigna el dato del parametro al struct del nodo
	nd->data = stoi(linea);
	//El apuntador raiz de la clase ahora apunta al nuevo nodo
	raiz = nd;
	//El numero de elementos a leer en el archivo se reduce por uno por el nodo recién creado
	tam--;

	for (int i = 0; i<tam; i++) {
		archivo_entrada.getline(linea, sizeof(linea));
		//Se inserta el nodo en el Arbol con la funcion insertar de la clase
		insertar(stoi(linea));
	}

	archivo_entrada.close();
}

void  Arbol::insertar(int dato) {
	//Se crea el node con nombre nd
	Node * nI = new Node;				//nI = Nodo a Insertar
	//Se asigna el dato del parametro al struct del nodo
	nI->data = dato;
	//Se checa que exista una raiz en la clase Arbol, si no la hay el nodo a ser insertado se convierte en raiz
	if (raiz == NULL) {
		raiz = nI;
	}
	//Se avanza al nodo raiz
	Node *cN = raiz;					//cN =currentNode

	//el checar current node es null seriua repetitivo ya que se checo antes de entrar, 
	while (cN->pointDer != NULL || cN->pointIzq != NULL) {
		if (nI->data > cN->data) {//Derecha
			if (cN->pointDer == NULL) {
				cN->pointDer = nI;
			}else{
				cN = cN->pointDer;
			}
		}else{//Izquierda
			if (cN->pointIzq == NULL) {
				//Se inserta nodo
				cN->pointIzq = nI;
			}else {
				cN = cN->pointIzq;
			}
		}
	}
}

bool  Arbol::buscar(int dato, Node *&lugar) {
	//False es si no encuentra el dato, pero no tiene que recorrer todos los nodos, como el arbol binario esta ordenado, solo tiene que buscar un
	//numero de nodos hasta encontrar el dato, o identificar que no existe

	//Insert deberia usar buscar
	return false;
}

bool  Arbol::elimina(int dato) {
	//Se tienen 4 opciones de eliminar si es raiz, si tiene 0 hijos, 1 j=hijo izq y uno derecho
	return false;
}

void  Arbol::imprime() {//INORDEN

}



#endif