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
    
    void crearArbol(NodoArbol *&n);
    void recoridoPreOrden();
    void recoridoInOrden();
    void recoridoPostOrden();
};

ArbolBinario::ArbolBinario(){
}

NodoArbol *ArbolBinario::getRaiz(){
    return raiz;
}

//Por cada nodo que se agrega se crea un arbol nuevo de forma recursiva
void ArbolBinario::crearArbol(NodoArbol *&n){//con la referencia se modifica el original
    int dato;
    cout << "\nIntroducir dato que va a contener nodo" << endl;
    cin >> dato;
    //Crear nodo
    n = new NodoArbol(dato);
    
    bool afi;
    cout << "\nTiene hijo izquierdo" << endl; //0 = False y 1 = True
    cin >> afi;
    if(afi){//Se vuelve a llamar a la funcion de forma recursiva
        NodoArbol * temp = n->getHijoIzq();
        crearArbol(temp);
    }

    cout << "\nTiene hijo derecho" << endl;
    cin >> afi;
    if(afi){
        NodoArbol * temp = n->getHijoDer();
        crearArbol(temp);
    }
}
#endif /* ArbolBinario_h */
