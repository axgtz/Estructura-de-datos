//
//  main.cpp
//  Linked-Lists
//
//  Created by Alex Gutz on 3/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
//#include "Lista.h"

using namespace std;


struct node {
    int data;
    node *pointer;
};


//----Lista Ligada----
class Lista {
private:
    node *primero = NULL; //Apuntador de inicio, primero apunta a null
    
public:
    Lista();
    
    void insertaInicio(int dato);
    void insertaFinal(int dato);
    bool insertaDespues(int dato, int ref);
    
    bool eliminaPrimero(int &dato);    //El parametro es para que se guarde el elemento expulsado en la variable temporal
    bool eliminaUltimo(int &dato);
    bool eliminaNodo(int ref, int &dato);
    
    
    void imprimeLista();
};

Lista::Lista(){
}

void Lista::insertaInicio(int dato){
    //Se crea el node con nombre nd
    node * nd = new node;
    //Se asigna el dato del parametro al struct del nodo
    nd->data = dato;
    //El apuntador del nodo nd recien creado apunta al nodo que previamente fue el primero, si no habia primero apunta a NULL
    nd->pointer = primero;
    //El apuntador primero de la clase lista ahora apunta al nodo nd
    primero = nd;
}

void Lista::insertaFinal(int dato){
    //Se crea el node con nombre nd
    node * nd = new node;
    //Se asigna el dato del parametro al struct del nodo
    nd->data = dato;
    //Se recorre la lista hasta llegar al final, porque el ultimo nodo apunta a NULL
    
}

bool Lista::insertaDespues(int dato,  int ref){
    //if()return false;
    
    //si llega al pointer de false significa que no existe la referencia
    return true;
}

bool Lista::eliminaPrimero(int &dato){
    return false;
}

bool Lista::eliminaUltimo(int &dato){
    return false;
}

bool Lista::eliminaNodo(int ref, int &dato){
    return false;
}


void Lista::imprimeLista(){
    node *nd = primero;
    do{
        cout << nd->data << " - ";
        nd = nd->pointer;
    }while(nd->pointer != NULL);
    cout << endl;
}

/*
 //----Nodo----
 class Nodo {
 private:
 int *pointer;
 int dato;
 public:
 Nodo(int &pointer, int dato){
 this->pointer = pointer;
 this->dato = dato;
 }
 };
 
 */

int main(int argc, const char * argv[]) {
    Lista l;
c
    l.insertaInicio(10);
    l.insertaInicio(20);
    l.insertaInicio(30);
    l.insertaInicio(40);
    l.insertaInicio(50);
    
    l.imprimeLista();
    
    return 0;
}
