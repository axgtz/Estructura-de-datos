//  main.cpp
//  Created by Alex Gutz on 5/06/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.

#include <iostream>
#include "BST.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	Arbol a;

	a.crear("texto");
	a.imprime();

	/*Node * cN;
	
	if (a.buscar(0, cN)) {
		cout << "\n" << cN->data;
	}*/
	int i = 0;
	if (a.elimina(i)) {
		cout << "\n eliminar" << i <<"\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}
	if (a.elimina(i)) {
		cout << "\n eliminar" << i << "\t";
		a.imprime();
		i += 10;
	}

	if (a.elimina(15)) {
		cout << "\n eliminar" << 15 << "\t";
		a.imprime();
	}

	if (a.elimina(25)) {
		cout << "\n eliminar" << 25 << "\t";
		a.imprime();
	}

	if (a.elimina(75)) {
		cout << "\n eliminar" << 75 << "\t";
		a.imprime();
	}
	if (a.elimina(85)) {
		cout << "\n eliminar" << 85 << "\t";
		a.imprime();
	}
	if (a.elimina(76)) {
		cout << "\n eliminar" << 76 << "\t";
		a.imprime();
	}



	int x;
	cin >> x;
	return 0;
}