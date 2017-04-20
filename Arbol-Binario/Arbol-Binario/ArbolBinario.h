//
//  ArbolBinario.h
//  Arbol-Binario
//
//  Created by Alex Gutz on 4/17/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#ifndef ArbolBinario_h
#define ArbolBinario_h

#include <iostream>
#include "NodoArbol.h"

using namespace std;

class ArbolBinario {
private:
    NodoArbol * raiz = NULL;
public:
    ArbolBinario();
    
    //Getters
    NodoArbol * getRaiz();
    
    void crearArbol(NodoArbol *n);
    void recoridoPreOrden();
    void recoridoInOrden();
    void recoridoPostOrden();
};

ArbolBinario::ArbolBinario(){
}

NodoArbol * ArbolBinario::getRaiz(){
    return raiz;
}

//Por cada nodo que se agrega se crea un arbol nuevo de forma recursiva
void ArbolBinario::crearArbol(NodoArbol *n){//----agregar datos //Se tiene que mandar un nodo ya con un data como parametro
    //Asignar raiz
    raiz = n;
    
    bool afi;
    cout << "\nTiene hijo izquierdo" << endl; //0 = False y 1 = True
    cin >> afi;
    if(afi){//Se vuelve a llamar a la funcion de forma recursiva
        int dato;
        cout << "\n\tIntroducir dato que va a contener nodo" << endl;
        cin >> dato;
        //Crear nodo
        NodoArbol * newN = new NodoArbol();
        //Asignar dato a nodo
        newN->setDato(dato);
        n->setHijoIzq(newN);
        crearArbol(newN);
    }
    
    cout << "\nTiene hijo derecho" << endl;
    cin >> afi;
    if(afi){
        int dato;
        cout << "\n\tIntroducir dato que va a contener nodo" << endl;
        cin >> dato;
        //Crear nodo
        NodoArbol * newN = new NodoArbol();
        //Asignar dato a nodo
        newN->setDato(dato);
        n->setHijoDer(newN);
        crearArbol(newN);
    }
}
#endif /* ArbolBinario_h */
