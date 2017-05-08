//  main.cpp
//  Created by Alex Gutz on 5/06/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.

#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, const char * argv[]) {
	Arbol a;
	Node * cN;

	a.crear("texto");
	a.imprime();

	if (a.buscar(10, cN)) {
		cout << "\nSe encontro: " << cN->data;
	}

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(15);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(10);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(20);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(30);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(50);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(75);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(80);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(90);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(70);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(76);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(60);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(100);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(25);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(40);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(0);
	a.imprime();

	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.elimina(85);
	a.imprime();

	int x;
	cin >> x;
	return 0;
}
