#include <iostream>
#include <vector>

using namespace std;

template <class Type>

class Pila {
private:
	int arr*;

public:
	Pila();

	// Inserta un elemento en la pila. Regresa true si la operaci�n��
	// fue exitosa y false en caso contrario.
	bool push(int dato);
	// Saca un elemento de la pila. Regresa true si la operaci�n fue��
	// exitosa y false en caso contrario.
	bool pop(int &dato);
	// Regresa true si la pila est� llena.
	bool pilaLlena();
	// Regresa true si la pila est� vac�a.
	bool pilaVacia();
	// Imprime el valor de la variable top y todos los elementos de la��
	// pila en una pila en una fila.
	void imprimePila();
};

Pila() {

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
