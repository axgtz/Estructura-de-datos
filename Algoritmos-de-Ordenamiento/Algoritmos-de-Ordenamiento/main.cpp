//  main.cpp
//  Algoritmos de Ordenamiento
//
//  Created by Alex Gutz on 2/13/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//
#include "Arreglo.h"

int main(int argc, const char * argv[]) {
    
	Arreglo a("texto");

    a.mergeSort(0,9);
    
    cout << endl <<endl;
    a.print();
    //Evitar que se cierre la conpsola en Visual studio
	int x;
	cin >> x;
	//Evitar que se cierre la consola en mac
    return 0;
}
