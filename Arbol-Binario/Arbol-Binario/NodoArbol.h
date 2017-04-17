//
//  NodoArbol.h
//  Arbol-Binario
//
//  Created by Alex Gutz on 4/17/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#ifndef NodoArbol_h
#define NodoArbol_h

#include <iostream>

using namespace std;

class NodoArbol{
private:
    int dato = NULL;
    NodoArbol *hijoIzq = NULL;
    NodoArbol *hijoDer = NULL;
public:
    NodoArbol();
    //Getters
    int getDato();
    NodoArbol getHijoIzq();
    NodoArbol getHijoDer();
    //Setters
    void setDato(int dato);
    void setHijoIzq(NodoArbol *nI);
    void setHijoDer(NodoArbol *nD);
};

int NodoArbol::getDato(){
    return dato;
}

NodoArbol NodoArbol::getHijoIzq(){
    return *hijoIzq;
}

NodoArbol NodoArbol::getHijoDer(){
    return *hijoDer;
}

void NodoArbol::setDato(int dato){
    this->dato = dato;
}

void NodoArbol::setHijoIzq(NodoArbol *nI){
    hijoIzq = nI;
}

void NodoArbol::setHijoDer(NodoArbol *nD){
    hijoDer = nD;
}
#endif /* NodoArbol_h */




