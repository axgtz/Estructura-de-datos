//  main.cpp
//  Linked-Lists
//
//  Created by Alex Gutz on 3/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
#include "Lista.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Lista l;
    int dat;
    
    l.insertaFinal(30);
	l.insertaInicio(10);
	l.insertaFinal(50);

    l.imprimeLista();

	l.insertaDespues(70,50);
	l.imprimeLista();
    
    l.eliminaNodo(70,dat);
    cout << "\nelimina 70 " << dat << " \n";
    l.imprimeLista();
    
    l.eliminaPrimero(dat);
    cout << "\nelimina Primero: " << dat << " \n";
    l.imprimeLista();
    
	int x;
	cin >> x;
    return 0;
}
