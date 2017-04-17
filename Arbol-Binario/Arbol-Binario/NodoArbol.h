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
};


class ArbolBinario{
private:
    NodoArbol * raiz;
public:
    ArbolBinario();
    
    void crearArbol(NodoArbol *n);
    
};

void crearArbol(NodoArbol *n){
    
}

#endif /* NodoArbol_h */
