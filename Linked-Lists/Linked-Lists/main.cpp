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
    //Se checa que la lista no este vacia
    if(primero == NULL){
        insertaInicio(dato);//Si la lista esta vacia, se llama inserta inicio con el mismo parametro
        return ; //Se agrega el return para acabar la funcion y que no se agregue dos veces
    }
    //Se avanza a el primer nodo
    node *nd = primero;
    //Se recorre la lista hasta llegar al final, porque el ultimo nodo apunta a NULL
    while (nd->pointer != NULL) {
        nd = nd->pointer;
    }
    //Se crea un nuevo nodo
    node * newNodo = new node;
    //Se le agrega el dato al nuevo nodo
    newNodo->data = dato;
    //Se le asigna el apuntador al nodo anterior para que apunte al nuevo
    nd->pointer = newNodo;
	//Si no se le asigna NULL, puede que no funcione
	newNodo->pointer = NULL;
}

bool Lista::insertaDespues(int dato,  int ref){
    //Se checa que la lista no este vacia
    if(primero == NULL)return false;
    
	//Se avanza a el primer nodo
	node *nd = primero;

	//Se hace un ciclo para encontrar el pointer con la referencia, tambienh se checa que no s ehalla llegado al final del ciclo
	while (nd->data != ref && nd->pointer != NULL) {
		nd = nd->pointer;
	}
    
	if (nd->data == ref) {
		//Se crea un nuevo nodo
		node * newNodo = new node;
		//Se le agrega el dato al nuevo nodo
		newNodo->data = dato;
		//Se le asigna el pointer al nuevo nodo, para que apunte al siguiente nodo del nodo que contiene el dato de referencia
		newNodo->pointer = nd->pointer;
		//El nodo que cointiene la referencia se le asigna que apunte al nodo recien creado.
		nd->pointer = newNodo;
		return true;
	}

    return false;
}

bool Lista::eliminaPrimero(int &dato){
    //Se checa que la lista no este vacia
    if(primero == NULL)return false;
    //Se avanza a el primer nodo
    node *nd = primero;
    //Se guarda el dato en el espacio de memoria que fue mandado como parametro
    dato = nd->data;
    //Se guarda el apuntador del siguiente nodo para evitar que se pierda la lista
    primero = nd->pointer;
    return true;
}

bool Lista::eliminaUltimo(int &dato){
	//Se checa que la lista no este vacia
	if (primero == NULL)return false;

	//Avanzar al primer nodo
	node *nd = primero;

	//Si solo hay un nodo, se elimina la referencia del head de la clase
	if (nd->pointer == NULL) {
		primero = NULL;
		return true;
	}

    //Se checa el siguiente apuntador del siguiente nodo, en el que se encuentra
    while (nd->pointer->pointer != NULL) {
        nd = nd->pointer;
    };
	//Se guarda el dato del nodo que va a ser eliminado
	dato = nd->pointer->data;
	//El pointer del nodo anterior ahora apounta a Null, por lo tanto ya no se puede accesar al sieguiente nodo
	nd->pointer = NULL;
    return true;
}

//Elimina el nodo que contiene la referencia
bool Lista::eliminaNodo(int ref, int &dato){//------------not finished-
    //Se checa que la lista no este vacia
    if(primero == NULL)return false;
    
    //Se avanza al primer nodo
    node *nd = primero;
    
    //Si es el primer nodo, se checa si contiene la referencia y si la tiene se elimina el primer nodo
    if (nd->data == ref) {
        //Se guarda en el parametro dato la información que contenia el nodo
        dato = nd->data;
        //Se checa si es el primer nodo
        if(nd->pointer == NULL){
            primero = NULL;
        }else{
            primero = nd->pointer;
        }
        return true;
    }
    
    //Se va revisando la lista nodo por nodo, hasta que se acabe la lista o se encuentre el nodo que contiene la referencia
    while (nd->pointer != NULL) {
        if(nd->pointer->data == ref){
            //Se guarda en el parametro dato, la información que contenia el nodo
            dato = nd->pointer->data;
            
            //Se elimina el pointer que apuntaba al nodo que contenia la referencia y ahorta apunt al siguiente
            nd->pointer = nd->pointer->pointer;
            return true;
        }
        nd = nd->pointer;
    }
    //Regresa falso si no encontro el dato de referencia
    return false;
}


void Lista::imprimeLista(){
    if(primero == NULL)return;//Para evitar que salga error si la lista esta vacia
    node *nd = primero;
	cout << nd->data;
	while (nd->pointer != NULL) {
        nd = nd->pointer;
		cout << " - "<<  nd->data ;
	};

    cout << endl;
}

int main(int argc, const char * argv[]) {
    Lista l;
    int dat;
    
    l.insertaFinal(30);
	l.insertaFinal(40);
	l.insertaInicio(20);
	l.insertaInicio(10);
	l.insertaFinal(50);
	l.insertaInicio(5);

    l.imprimeLista();

	l.insertaDespues(70,50);
	l.imprimeLista();

	l.insertaDespues(35, 30);
	l.imprimeLista();
	
    l.eliminaNodo(35,dat);
    cout << "\nelimina 35 " << dat << " \n";
	l.imprimeLista();
        l.imprimeLista();
    
    l.eliminaNodo(5,dat);
    cout << "\nelimina 55 " << dat << " \n";
    l.imprimeLista();
    
    l.eliminaNodo(70,dat);
    cout << "\nelimina 70 " << dat << " \n";
    l.imprimeLista();

	int x;
	cin >> x;
    return 0;
}
