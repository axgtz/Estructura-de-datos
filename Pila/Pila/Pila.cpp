//Roberto Alejandro Gutiérrez Guillén			A01019608
#include <iostream>

using namespace std;

class Pila {
private:
	int* arr;

public:
	Pila(int max);

	// Inserta un elemento en la pila. Regresa true si la operación  
	// fue exitosa y false en caso contrario.
	bool push(int dato);
	// Saca un elemento de la pila. Regresa true si la operación fue  
	// exitosa y false en caso contrario.
	bool pop(int &dato);
	// Regresa true si la pila está llena.
	bool pilaLlena();
	// Regresa true si la pila está vacía.
	bool pilaVacia();
	// Imprime el valor de la variable top y todos los elementos de la  
	// pila en una pila en una fila.
	void imprimePila();
};

Pila(int max) {
	arr[max];
}


bool push(int dato) {
	return true;
}


bool pop(int &dato) {
	return true;
}


bool pilaLlena() {
	return true;
}


bool pilaVacia() {
	return true;
}


void imprimePila() {

}

int main() {
	
}