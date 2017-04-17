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

//-----------------------
class ArbolBinario{
private:
    NodoArbol * raiz = NULL;
public:
    ArbolBinario();
    
    void crearArbol(NodoArbol *n);
    void recoridoPreOrden();
    void recoridoInOrden();
    void recoridoPostOrden();
};

ArbolBinario::ArbolBinario(){
}

//Por cada nodo que se agrega se crea un arbol nuevo de forma recursiva
void ArbolBinario::crearArbol(NodoArbol *n){//----agregar datos //Se tiene que mandar un nodo ya con un data como parametro
    //Asignar raiz
    raiz = n;
    
    bool afi;
    cout << "\nTiene hijo izquierdo" << endl;
    cin >> afi;
    if(afi){//Se vuelve a llamar a la funcion de forma recursiva
        int dato;
        cout << "\n\tIntroducir dato que va a contener nodo" << endl;
        cin >> dato;
        //Crear nodo
        NodoArbol * newN = new NodoArbol();
        //Asignar dato a nodo
        newN->setDato(dato);
        //crearArbol(n->setHijoIzq());
    }
    
    cout << "\nTiene hijo derecho" << endl;
    cin >> afi;
    if(afi){
       // crearArbol(n->asignarHiijoIzq());
    }
    
}

#endif /* NodoArbol_h */




