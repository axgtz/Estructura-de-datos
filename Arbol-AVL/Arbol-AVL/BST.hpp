//Roberto Alejandro Gutiérrez Guillén		A01019608
#include <iostream>

//Librerias de lectura de datos
#include <fstream>
#include <sstream>

#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node {
	int data = NULL, altura = NULL;
	Node *pointIzq = NULL, *pointDer = NULL;
};

class Arbol {
private:
	Node * raiz;
	void imprimeRecursivo(Node *);
	Node *  insertarRecursivo(int data, Node * raiz);
	int altura(Node *n);
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
//Constructor
Arbol::Arbol() {}

//++++Funciones de ayuda++++
//Funcion para calcular la altura de un nodo
int Arbol::altura(Node *n){
	return n == NULL ? -1 : n->altura;  //Conditonal Operator: if (n == NULL){return -1;}else {n->altura;}
}
//Max regresa el maximo entre el nodo izquierdo y el derecho
int max(int nIzq, int nDer){
	return nIzq > nDer ? nIzq : nDer;
}

//++++Funciones Principales con sus funciones hermanas recursivas++++
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
//Funcion de Insertar que llama a insertar recursivo
void  Arbol::insertar(int dato) {
	raiz = insertarRecursivo(dato, raiz);
}

Node *Arbol::insertarRecursivo(int data, Node * n) {
	if (n) {//Igual que n == NULL
	Node * n;
	n->data;
	}else if (data < n->data){
		n->pointIzq = insertarRecursivo(data, n->pointIzq);
		if (altura(n->pointIzq) - altura(n->pointDer) == 2)
			if (data < n->pointIzq->data)
				n = rotateWithLeftChild(n);
			else
				n = doubleWithLeftChild(n);
	}else if (data > n->data){
		n->pointDer = insertarRecursivo(data, n->pointDer);
		if (altura(n->pointDer) - altura(n->pointIzq) == 2)
			if (data > n->pointDer->data)
				n = rotateWithRightChild(n);
			else
				n = doubleWithRightChild(n);
	}
	n->altura = max(altura(n->pointIzq), altura(n->pointDer)) + 1;
	return n;
}

bool  Arbol::buscar(int dato, Node *&lugar) {
	if (raiz == NULL) return false;
	//Se avanza al nodo raiz
	Node * cN = raiz;
	while (cN) {
		if (dato == cN->data) {
			lugar = cN;		//Guarda el nodo que en la dirección		
			return true;
		}
		else if (cN->data > dato) {
			cN = cN->pointIzq;
		}
		else {
			cN = cN->pointDer;
		}
	}
	return false;
}

void  Arbol::imprime() {//INORDEN
	Node *cN = raiz;	//Se avanza al nodo raiz
	cout << "\n";
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
