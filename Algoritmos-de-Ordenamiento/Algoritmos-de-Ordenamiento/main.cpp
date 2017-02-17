//
//  main.cpp
//  Algoritmos de Ordenamiento
//
//  Created by Alex Gutz on 2/13/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <class Type>

class ManejadorArreglosGenerico {
    
private:
    int tam;
    vector <Type> vec;
    
public:
    ManejadorArreglosGenerico(string nombreArchivo,  vector <Type> v, int tam);
    
    void lecturaDatos(string nombreArchivo);
    
    void swap(int a,int b);
    
    void print();
    
    //Metodos de Ordenamiento
    void selectionSort();
    
    void insertionSort();
};

//CONSTRUCTOR
template <class Type>   //Se tiene que poner antes de cada metodo
ManejadorArreglosGenerico<Type>::ManejadorArreglosGenerico(string nombreArchivo,  vector <Type> v, int tam) {
    this->tam = tam;
    vec = v;
}

//LECTURA DE DATOS

//SWAP
template <class Type>
void ManejadorArreglosGenerico<Type>::swap(int a,int b){
    Type temporal = vec[b];
    vec[b] = vec[a];
    vec[a] = temporal;
}

//PRINT
template <class Type>
void ManejadorArreglosGenerico<Type>::print(){
    for(int i = 0 ; i < tam; i++){
        cout << vec[i] << " - ";
    }
    cout << endl;
}

template <class Type>
void ManejadorArreglosGenerico<Type>::selectionSort(){
    int posMenor;
    print();
    for(int i = 0; i < tam;i++){
        posMenor = i;
        for(int j = i + 1 ; j < tam ; j++){
            if(vec[posMenor] > vec[j]){//Se encuentra uno menor que el num seleccionado
                posMenor = j;
            }
        }
        //swap(vec[i],vec[posMenor],arr);
        swap(i,posMenor);
        print();//Imprimir despues del swap
    }
    
}


template <class Type>
void ManejadorArreglosGenerico<Type>::insertionSort() {
    for(int i =0 ; i < tam; i++){
        
        
    }
}


/*
 
 
    void bubbleSort(){
        bool bandera = false;
        
        //if swap, si bandera es false cuando acabe, entonces se acaba el while
        bandera = true;
    }
    

 */
int main(int argc, const char * argv[]) {
     vector <int> v = {90,70,00,50,30,10,60,80,20,40};
    
    ManejadorArreglosGenerico<int> *a = new  ManejadorArreglosGenerico<int>("pepe",v, 10);
    a->print();
    cout << "Selection Sort: " << endl;
    a->selectionSort();
    
    return 0;
}
