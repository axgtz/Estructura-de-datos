//  main.cpp
//  Linked-Lists
//
//  Created by Alex Gutz on 5/06/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.

#include <iostream>
#include "BST.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
	Arbol a;

	a.crear("texto");
	a.imprime();

	Node * cN;

	if (a.buscar(0, cN)) {
		cout << "\n" << cN->data;
	}
	int x;
	cin >> x;
	return 0;
}