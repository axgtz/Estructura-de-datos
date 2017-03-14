//Roberto Alejandro Gutierrez Guillen			A01019608
#include <iostream>

using namespace std;

class Pila {
private:
	int *pila;
	int top;
	int MAX;

public:
	Pila(int max);

	// Inserta un elemento en la pila. Regresa true si la operacion
	// fue exitosa y false en caso contrario.
	bool push(int dato);
	// Saca un elemento de la pila. Regresa true si la operacion fue
	// exitosa y false en caso contrario.
	bool pop(int &dato);
	// Regresa true si la pila esta llena.
	bool pilaLlena();
	// Regresa true si la pila esta vacia.
	bool pilaVacia();
	// Imprime el valor de la variable top y todos los elementos de la
	// pila en una pila en una fila.
	void imprimePila();
};

Pila::Pila(int max) {
	if (max < 0) {
		cout << "No se puede tener un tamano menor a 1" << endl;
	}
	else {
		this->MAX = max;
		pila = new int[MAX];       //Asignar el espacio de la pila
		top = -1;
	}
}


bool Pila::push(int dato) {
	if (pilaLlena())return false;
	top++;
	pila[top] = dato;

	return true;
}


bool Pila::pop(int &dato) {
	if (pilaVacia())return false;
	dato = pila[top];				//El valor que se encuentra dentro de la pila no se reescribe porque solo
	top--;							//se gastaria tiempo,  se mueve el top entonces no se puede acceder al valor
	return true;					//y cuando se agrege un elemento es cuando se sobreescribe
}


bool Pila::pilaLlena() {
	if (top == MAX - 1)return true;
	return false;
}


bool Pila::pilaVacia() {
	if (top == -1)return true;//Esta vacia
	return false;
}


void Pila::imprimePila() {
	cout << "Top: " << top << endl;
	for (int i = top; i >= 0; i--) {
		cout << pila[i] << " ";
	}
	cout << endl << endl;
}

