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
	Node(int d) {
		data = d;
		altura = 1;
	}
	Node() {};
};

class Arbol {
private:
	//Atributos
	Node * raiz = NULL;
	//funciones
	int altura(Node *n);
	int max(int a, int b);
	int getBalance(Node * n);
	Node * rotarDerecha(Node *r);
	Node * rotarIzquierda(Node *r);
	Node * minNode(Node * node);
	Node * insertarRecursivo(int data, Node *raiz);
	Node * deleteNodeRecursivo(int dato, Node * raiz);
	void imprimeRecursivo(Node *);

public:
	//Constructor
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
//++++Funciones de Ayuda+++
int Arbol::max(int a, int b){
	return (a > b) ? a : b;		 //Conditonal Operator: if (a > b){return a;}else {return b}
}

int Arbol::altura(Node *n) {
	return (n == NULL) ? 0 : n->altura;//si n es null entonces
}

// Se obitene el balance del nodo que se envia
int  Arbol::getBalance(Node * n) {
	return(n) ? 0 : (altura(n->pointIzq) - altura(n->pointDer));
}

//Esta funcion va a rotar a la derecha el arbol tomando en cuenta que r es la raiz, va a convertir a nR en la raiz y r se va a volver su hijo derecho
 Node * Arbol::rotarDerecha(Node *r){
	Node * nR = r->pointIzq;			//nR va aser la nueva raiz
	Node * nTemp = nR->pointDer;		//nTemp es un nodo temporal para guardar el apuntador del hijo derecho del nodo que se convierte en raiz

	// Rotar
	nR->pointDer = r;
	r->pointIzq = nTemp;

	// Actualizar alturas de nodos
	r->altura = max(altura(r->pointIzq), altura(r->pointDer)) + 1;
	nR->altura = max(altura(nR->pointIzq), altura(nR->pointDer)) + 1;

	// Regresar nueva raiz 
	return nR;
}

 Node * Arbol::minNode(Node * node) {
	 Node* nC = node;//current Node
	 //Loop para encontrar el hijo de hasta la izquierda, ya que seria el valor minimo
	 while (nC->pointIzq != NULL) {
		 nC = nC->pointIzq;
	 }
	 return nC;
 }
 //Esta funcion va a rotar a la izquierda el arbol tomando en cuenta que r es la raiz
 Node * Arbol::rotarIzquierda(Node *r) {//Se va a rotar el arbol y poner el nodo r como raiz
	 Node * nR = r->pointDer;
	 Node * nTemp = nR->pointIzq;

	 nR->pointIzq = r;
	 r->pointDer = nTemp;

	 r->altura = max(altura(r->pointIzq), altura(r->pointDer)) + 1;
	 nR->altura = max(altura(nR->pointIzq), altura(nR->pointDer)) + 1;

	 return nR;
 }


 //+++ Funciones Principales +++
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
		 return;
	 }

	 for (int i = 0; i<tam; i++) {
		 archivo_entrada.getline(linea, sizeof(linea));
		 //Se inserta el nodo en el Arbol con la funcion insertar de la clase
		 insertar(stoi(linea));
	 }

	 archivo_entrada.close();
 }

 void  Arbol::insertar(int dato) {
	 raiz = insertarRecursivo(dato, raiz);
 }

 // Recursive function to insert key in subtree rooted with node and returns new root of subtree.
 Node * Arbol::insertarRecursivo(int dato, Node * nodo) {
	 //Aqui es donde se insertael nodo de forma normal
	 if (nodo == NULL) {
		 return (new Node(dato));
	 }
	 if (dato < nodo->data) {//Se decide donde se inserta el nodo 
		 nodo->pointIzq = insertarRecursivo(dato, nodo->pointIzq);//Insertar Izquierdo
	 }else if (dato > nodo->data) {
		 nodo->pointDer = insertarRecursivo(dato, nodo->pointDer);//Insertar Derecho
	 }else{ 
		 return nodo;//Se devuelve el nodo ya que el dato esta duplicado
	 }
	 //Se actualiza altura del nodo  
	 nodo->altura = 1 + max(altura(nodo->pointIzq),altura(nodo->pointDer));

	 //Se obtiene el balance apra saber si la inclusión del nodo vuelve al arbol desbalanceado
	 int balance = getBalance(nodo);

	 //Hay 4 casos si el nodo se vuelve desbalanceado
	 // 1. Se tiene que rotar a la derecha 
	 if (balance > 1 && dato < nodo->pointDer->data){
		 return rotarDerecha(nodo);
	 }
	 // 2.Se rota a la izquierda porque la altura del subarbol de la derecha supera 1 
	 if (balance < -1 && dato > nodo->pointDer->data) {
		 return rotarIzquierda(nodo);
	 }
	 // 3.Se balancea el nodo hijo del nodo izquierdo y el nodo se rota a la derecha
	 if (balance > 1 && dato > nodo->pointIzq->data){
		 nodo->pointIzq = rotarIzquierda(nodo->pointIzq);
		 return rotarDerecha(nodo);
	 }
	 // 4.Se rota el hijo derecho del nodo a la derecha y el nhodo se rota a la izquierda
	 if (balance < -1 && dato < nodo->pointDer->data){
		 nodo->pointDer = rotarDerecha(nodo->pointDer);
		 return rotarIzquierda(nodo);
	 }
	 //Si el nodo no desbalancea el arbol se manda sin cambiar
	 return nodo;
 }

bool Arbol::elimina(int dato) {
	Node * nI;
	if (buscar(dato, nI)) {
		raiz = deleteNodeRecursivo(dato, raiz);
		return true;
	}
	return false;
}
//Funcion recursiva para eliminar el nodo, regresa el root del subarbol modificado, ya que se mantiene el balance aun al borrar
Node * Arbol::deleteNodeRecursivo(int dato, Node * raizTemp) {
	if (raizTemp == NULL) { return raizTemp; }	// Si es null se regresa, caso base para recursión
	// REvisa el dato a ser eliminado para ver si se va al subarbol izquierdo o al derecho
	if (dato < raizTemp->data) {
		raizTemp->pointIzq = deleteNodeRecursivo(dato, raizTemp->pointIzq);
	}else if (dato > raizTemp->data) {
		raizTemp->pointDer = deleteNodeRecursivo(dato, raizTemp->pointDer);
	}else {//Entra al else porque el dato a buscar fue encontrado3
	   // Si tiene un hijo o no tiene hijos
		if ((raizTemp->pointIzq == NULL) || (raizTemp->pointDer == NULL)) {
			Node *temp = raizTemp->pointIzq ? raizTemp->pointDer : raizTemp->pointDer;
			if (temp == NULL) {			// Si no tiene hijos
				temp = raizTemp;
				raizTemp = NULL;
			}else { // Si solo tiene un hijo
				*raizTemp = *temp; // Copy the contents of
			}
			delete(temp);// Eliminar el nodo ya que no tiene hijos
		}else {
			// Nodo con dos hijos, se obtiene el que va a remplazar el nodo que sera eliminado
			Node * temp = minNode(raizTemp->pointDer);
			raizTemp->data = temp->data;				//Se copia la informacion del nodo a ser eliminado al nodo que va a remplazarlo
			raizTemp->pointDer = deleteNodeRecursivo(temp->data, raizTemp->pointDer);			// Delete the inorder successor
		}
	}
	// If the tree had only one node then return, caso base 2
	if (raizTemp == NULL) {
		return raizTemp;
	}
	raizTemp->altura = 1 + max(altura(raizTemp->pointIzq), altura(raizTemp->pointDer));	// Actualizar alturas
	int balance = getBalance(raizTemp);			//Checa el balance del arbol
	//Mismos casos que en creaación
	if (balance > 1 && getBalance(raizTemp->pointIzq) >= 0) {
		return rotarDerecha(raizTemp);
	}
	if (balance > 1 && getBalance(raiz->pointIzq) < 0) {
		raizTemp->pointIzq = rotarIzquierda(raizTemp->pointIzq);
		return rotarDerecha(raizTemp);
	}

	if (balance < -1 && getBalance(raizTemp->pointDer) <= 0) {
	return rotarIzquierda(raizTemp);
	}
	if (balance < -1 && getBalance(raizTemp->pointDer) > 0){
		raizTemp->pointDer = rotarDerecha(raizTemp->pointDer);
		return rotarIzquierda(raizTemp);
	}
	return raizTemp;
}

bool Arbol::buscar(int dato, Node *&lugar) {
	 if (raiz == NULL) return false;
	 //Se avanza al nodo raiz
	 Node * cN = raiz;
	 while (cN) {
		 if (dato == cN->data) {
			 lugar = cN;		//Guarda el nodo que en la dirección		
			 return true;
		 }else if (cN->data > dato) {
			 cN = cN->pointIzq;
		 }else {
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
