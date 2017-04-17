//
//  main.cpp
//  Arbol-Binario
//
//  Created by Alex Gutz on 4/17/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
#include "NodoArbol.h"
#include "ArbolBinario.h"

using namespace std;

int main(int argc, const char * argv[]) {
    NodoArbol * n = new NodoArbol();
    
    ArbolBinario * a = new ArbolBinario();
    
    a->crearArbol(n);
    
    int x;
    cin >> x;
    return 0;
}
