//
//  main.cpp
//  Algoritmos de Ordenamiento
//
//  Created by Alex Gutz on 2/13/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

using namespace std;

template <class T>
class manejadorArreglosGenerico {
    int tam = 0;
    T *arr;
    
public:
    manejadorArreglosGenerico(int tam,T arr[]){
        this->tam = tam;
        this->arr = arr[tam];
    }
    
    void imprimeArreglo(){
        for(int i = 0 ; i < tam; i++){
            cout << arr[i] << " - ";
        }
        cout << endl;
    }
    
    
    void swap(T a,T b,T arr[]){
        T temporal = arr[b];
        arr[b] = arr[a];
        arr[a] = temporal;
    }
    
    
    void selectionSort(T arr[],int num){
        int posMenor;
        
        for(int i = 1;i>num;i++){
            posMenor = i;
            for(int j = i+1 ; i>num ; j++){
                if(arr[posMenor] > arr[j]){//Se encuentra uno menor que el num seleccionado
                    posMenor = j;
                }
            }
            swap(arr[i],arr[posMenor],arr);
        }
        imprimeArreglo();
    }
    
};
int main(int argc, const char * argv[]) {
    
    
    
    
    
    
    return 0;
}
