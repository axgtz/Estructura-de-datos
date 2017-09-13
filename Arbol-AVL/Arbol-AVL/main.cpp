//  main.cpp
//  Created by Alex Gutz on 5/06/17.
//  Copyright � 2017 Alejandro Gutierrez. All rights reserved.

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

    a.elimina(15);
	cout << "\n\n Eliminar: 15\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(10);
	cout << "\n\n Eliminar: 10\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(20);
	cout << "\n\n Eliminar: 20\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(30);
	cout << "\n\n Eliminar: 30\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(50);
	cout << "\n\n Eliminar: 50\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(75);
	cout << "\n\n Eliminar: 75\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(80);
	cout << "\n\n Eliminar: 80\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(90);
	cout << "\n\n Eliminar: 90\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(70);
	cout << "\n\n Eliminar: 70\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(76);
	cout << "\n\n Eliminar: 76\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(60);
	cout << "\n\n Eliminar: 60\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(100);
	cout << "\n\n Eliminar: 100\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(25);
	cout << "\n\n Eliminar: 25\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(40);
	cout << "\n\n Eliminar: 40\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(0);
	cout << "\n\n Eliminar: 0\t Raiz:" << a.raiz->data;
	a.imprime();

    a.elimina(85);
	cout << "\n\n Eliminar: 85\t Raiz:" << a.raiz->data;
	a.imprime();

	int x;
	cin >> x;
	return 0;
}
