//
//  main.cpp
//  Linked-Lists
//
//  Created by Alex Gutz on 3/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

using namespace std;


struct node {
    int data;
    node *pointer;
};


//----Lista Ligada----
class Lista {
private:
    node *primero; //Apuntador de inicio, primero apunta a null

public:
    Lista();
    
    void insertaInicio(int dato);
    void insertaFinal(int dato);
    bool insertaDespues(int dato, int ref);
    
    bool eliminaPrimero(int &dato);    //El parametro es para que se guarde el
    bool eliminaUltimo(int &dato);     //elemento expulsado en la variable temporal
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
    
    nd->pointer = primero;
    
    primero = nd;
}

void Lista::insertaFinal(int dato){
    
}

bool Lista::insertaDespues(int dato,  int ref){
    //if()return false;
    
    return true;
}


void imprimeLista(){
    
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
    
    
    
    // insert code here...
    
    cout << "Hello, World!\n";
    return 0;
}
