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

//-----------------------
class ArbolBinario{
private:
    NodoArbol * raiz;
public:
    ArbolBinario();
    
    void crearArbol(NodoArbol *n);
    void recoridoPreOrden();
    void recoridoInOrden();
    void recoridoPostOrden();
};

void ArbolBinario::crearArbol(NodoArbol *n){//Recursivo
    //Asignar raiz
    
    crearArbol(n->asignarHiijoIzq());
    //	crearArbol(n->asignarHiijoDer(<#NodoArbol *nI#>));
}

#endif /* NodoArbol_h */
