//
//  main.cpp
//  Algoritmos de Ordenamiento
//
//  Created by Alex Gutz on 2/13/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

template <class Type>

class ManejadorArreglosGenerico {
    
private:
    int tam;
    vector <Type> vec;
    
public:
	ManejadorArreglosGenerico(string nombreArchivo);

    ManejadorArreglosGenerico(vector <Type> v, int tam);
    
    void lecturaDatos(string nombreArchivo);
    
    void swap(int a,int b);
    
    void print();
    
    //Metodos de Ordenamiento
    void selectionSort();
    
    void insertionSort();

	void bubbleSort();
};

//CONSTRUCTOR que hace lectura de datos, pero solo puede guardar int
template <class Type>   //Se tiene que poner antes de cada metodo
ManejadorArreglosGenerico<Type>::ManejadorArreglosGenerico(string nombreArchivo) {
	lecturaDatos(nombreArchivo);	//lectura de datos para subir el contenido del text file al vector de la clase
}


//CONSTRUCTOR que recibe un vector
template <class Type>   
ManejadorArreglosGenerico<Type>::ManejadorArreglosGenerico(vector <Type> v, int tam) {
	this->tam = tam;
	vec = v;
}

//LECTURA DE DATOS
template <class Type>   
void ManejadorArreglosGenerico<Type>::lecturaDatos(string nombreArchivo) {
	ifstream archivo_entrada; //Declarar variable que se usa para acceder a las funciones de ifstream

	string st = nombreArchivo + ".txt";

	//int tamTemp = 1;//Varaibale de tamaño temporal

	if (archivo_entrada.fail()) {
		cout << "Error al abrir el archivo" << endl;
		vec[0] = { -1 };
		//return tamTemp;
	}
	
	char linea[128];

	//Usando la variable linea se extrae toda la primera linea del archivo de texto
	archivo_entrada.getline(linea, sizeof(linea));

	//Se guarda el numero de numeros que va a contener el arreglo en el atributo de la clase entera "tam"
	//stringstream str(linea);
	//str >> tam;
	tam = atoi(linea);
	cout << tam << endl;




	while (!archivo_entrada.eof()) {
		archivo_entrada.getline(linea, sizeof(linea));
		vec.push_back(stoi(linea));
	}

	archivo_entrada.close();

	//return tam; //Se regresa el tamaño que se leyo en el archivo para que se pueda cambiar la variable de la clase en el constructor
}

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

//Selection Sort
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
        swap(i,posMenor);
        print();//Imprimir despues del swap
    }
    
}

//Insertion Sort
template <class Type>
void ManejadorArreglosGenerico<Type>::insertionSort() {
    for(int i =0 ; i < tam; i++){
        
        
    }
}

//Bubble Sort
template <class Type>
void ManejadorArreglosGenerico<Type>::bubbleSort() {
	bool bandera = false;

	//if swap, si bandera es false cuando acabe, entonces se acaba el while
	bandera = true;
}

int main(int argc, const char * argv[]) {
    vector <int> v = {90,70,00,50,30,10,60,80,20,40};
    
    ManejadorArreglosGenerico<int> *a = new  ManejadorArreglosGenerico<int>("texto");
    a->print();
    cout << "Selection Sort: " << endl;
    a->selectionSort();
    
	//Evitar que se cierre la consola en Visual studio
	int x;
	cin >> x;
	//Evitar que se cierre la consola en mac
    return 0;
}
