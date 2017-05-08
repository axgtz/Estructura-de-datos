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

	a.elimina(15);
	a.imprime();

	a.elimina(10);
	a.imprime();

	a.elimina(20);
	a.imprime();

	a.insertar(15);
	a.imprime();

	a.elimina(15);
	a.imprime();

	a.elimina(30);
	a.imprime();

	a.elimina(50);
	a.imprime();

	a.elimina(75);
	a.imprime();

	a.elimina(80);
	a.imprime();

	a.elimina(90);
	a.imprime();

	a.elimina(70);
	a.imprime();

	a.elimina(76);
	a.imprime();

	a.elimina(60);
	a.imprime();

	a.elimina(100);
	a.imprime();

	a.elimina(25);
	a.imprime();

	a.elimina(40);
	a.imprime();

	int x;
	cin >> x;
	return 0;
}
