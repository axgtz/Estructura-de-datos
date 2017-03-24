//
//  main.cpp
//  Linked-Lists
//
//  Created by Alex Gutz on 3/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

using namespace std;

//----Lista Ligada----
class Lista {
private:
    int *primero; //Apuntador de inicio, primero apunta a null

public:
    Lista();
    
    void insertaInicio(int dato);
    void insertaFinal(int datp);
    bool insertaDespues(int dato, int ref);
    
    bool eliminaPrimero(int &dato);    //El parametro es para que se guarde el
    bool eliminaUltimo(int &dato);     //elemento expulsado en la variable temporal
    bool eliminaNodo(int ref, int &dato);
    
    void imprimeLista();
};

Lista::Lista(){
}

void Lista::insertaInicio(int dato){
    
}

//----Nodo----
class Node {
private:
    int *pointer;
    int dato;
public:
    Node();
};



int main(int argc, const char * argv[]) {
    
    // insert code here...
    
    cout << "Hello, World!\n";
    return 0;
}
