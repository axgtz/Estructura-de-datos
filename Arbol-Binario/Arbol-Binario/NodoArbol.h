//
//  NodoArbol.h
//  Arbol-Binario
//
//  Created by Alex Gutz on 4/17/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#ifndef NodoArbol_h
#define NodoArbol_h

class NodoArbol{
private:
    int dato;
    NodoArbol *hijoIzq;
    NodoArbol *hijoDer;
public:
    NodoArbol();
    void asignarHiijoIzq(NodoArbol *nI);
    void asignarHiijoDer(NodoArbol *nD);
};


class ArbolBinario{
private:
    NodoArbol * raiz;
public:
    ArbolBinario();
    
    void crearArbol(NodoArbol *n);
    
};

void crearArbol(NodoArbol *n){//Recursivo
    crearArbol(n->asignarHiijoIzq(<#NodoArbol *nI#>));
    //	crearArbol(n->asignarHiijoDer(<#NodoArbol *nI#>));
}

#endif /* NodoArbol_h */
