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
	Node *raiz = NULL;
	void imprimeRecursivo(Node *);
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
		return;
	}
	//Se avanza al nodo raiz
	Node * cN = raiz;					//cN =currentNode

	//el checar current node es null seriua repetitivo ya que se checo antes de entrar, -------no entra porque al principio el nodo raiz solo apunta a null
	while (cN) {
		if (dato > cN->data) {//Derecha
			if (cN->pointDer == NULL) {
				cN->pointDer = nI;
				break;
			}else{
				cN = cN->pointDer;
			}
		}else{//Izquierda
			if (cN->pointIzq == NULL) {
				//Se inserta nodo
				cN->pointIzq = nI;
				break;
			}else {
				cN = cN->pointIzq;
			}
		}
	}
}

bool  Arbol::buscar(int dato, Node *&lugar) {
	if (raiz == NULL) return false;
	//Se avanza al nodo raiz
	Node * cN = raiz;
	while (cN) {
		if (dato == cN->data){
			lugar = cN;		//Guarda el nodo que en la dirección		//---- en borrar Se tiene que decidir que nodo hijo lo va a remplazar
			return true;
		}else if (cN->data > dato){
			cN = cN->pointIzq;
		}else {
			cN = cN->pointDer;
		}
	}
	return false;
}

bool  Arbol::elimina(int dato) {
	if (raiz == NULL) {
		return false;
	}
	//Se avanza al nodo raiz
	/*
	Node * cN = raiz;           
	while (cN) {
		if (dato > cN->data) {//Derecha
			if (cN->pointDer == NULL) {
				cN->pointDer = nI;
				break;
			}
			else {
				cN = cN->pointDer;
			}
		}
		else {//Izquierda
			if (cN->pointIzq == NULL) {
				//Se inserta nodo
				cN->pointIzq = nI;
				break;
			}
			else {
				cN = cN->pointIzq;
			}
		}
	}*/
	//Se tienen 4 opciones de eliminar si es raiz, si tiene 0 hijos, 1 j=hijo izq y uno derecho
	return false;
}

void  Arbol::imprime() {//INORDEN
	Node *cN = raiz;	//Se avanza al nodo raiz
	imprimeRecursivo(cN);
}

void Arbol::imprimeRecursivo(Node * currentPointer) {
	if (currentPointer) {	//Si el pointer apunta a un Nodo
		imprimeRecursivo(currentPointer->pointIzq);
		cout << currentPointer->data << "  ";
		imprimeRecursivo(currentPointer->pointDer);
	}
}
#endif