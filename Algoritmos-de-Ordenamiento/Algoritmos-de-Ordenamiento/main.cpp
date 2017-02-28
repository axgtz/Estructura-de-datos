//  main.cpp
//  Algoritmos de Ordenamiento
//
//  Created by Alex Gutz on 2/13/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//
#include "Arreglo.h"

int main(int argc, const char * argv[]) {
    
    int v1[10] = {90,80,70,60,50,40,30,20,10,00};
    int v[11] = {100,90,70,00,50,30,10,60,80,20,40};
    
    ManejadorArreglos a(v ,11);

    a.mergeSort(0,10);
    
    cout << endl <<endl;
    a.print();
    //Evitar que se cierre la consola en Visual studio
	int x;
	cin >> x;
	//Evitar que se cierre la consola en mac
    return 0;
}
