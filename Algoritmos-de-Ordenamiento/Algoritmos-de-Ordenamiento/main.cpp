//
//  main.cpp
//  Algoritmos de Ordenamiento
//
//  Created by Alex Gutz on 2/13/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
#include <vector>

//Librerias de lectura de datos
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
    
    //Metodos de Busqueda
    int busquedaSecuencial(int a[], int n, int k);
    int busquedaBinaria(int a[], int primero, int ultimo, int k);
    
    //Metodos de Ordenamiento
    void selectionSort();
    
    void insertionSort();

	void bubbleSort();

    //Metodos de ordenamiento, se vana  hacer 2 versiones una que tenga que recibir un array y otra que use el existente
    //Array Nuevo
	void mergeSort(vector <Type> v, int n);
    void merge(vector <Type> v1,vector <Type> v2);
    
    void preQuickSort(vector <Type> v);//Agregar random shuffle antes de empezar quicksort
    void quickSort(vector <Type> v, int lo, int hi);
    int partition(vector <Type> v, int lo, int hi); //Regresa int porque es la posicion donde puso el pivote
    
    //Array Existente, el que esta en la clase
    void mergeSort(int start, int end);
    //void merge();
    
    void quickSort(int lo, int hi);
    int partition(int lo, int hi);
    
    
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

	archivo_entrada.open(st);

	if (archivo_entrada.fail()) {
		cout << "Error al abrir el archivo" << endl;
		vec[0] = { -1 };
	}
	
	char linea[128];

	//Usando la variable linea se extrae toda la primera linea del archivo de texto
	archivo_entrada.getline(linea, sizeof(linea));

	//Se guarda el numero de numeros que va a contener el arreglo en el atributo de la clase entera "tam"
	tam = stoi(linea);

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
        cout << vec[i];
		if (i + 1 != tam)//If es para que no imprima el guión después del último número 
			cout << " - ";
    }
    cout << endl;
}

///<--------Busquedas------->
//Busqueda Secuencial
int busquedaSecuencial(int a[], int n, int k) {
    int res = -1, i;
    for (i = 0;i<n;i++){
        if (k == a[i]) {
            res = i;
            return res;
        }
    }
    return res;
}

//Busqueda Binaria
int busquedaBinaria(int a[], int primero, int ultimo, int k) {
    if (ultimo < primero) {
        return -1;
    }
    else {
        int medio = (primero + ultimo) / 2;
        if (k == a[medio]) {
            return medio;
        }else if (k > a[medio]) {
            return busquedaBinaria(a, medio +1, ultimo, k);
        }
        else {
            return busquedaBinaria(a, primero, medio - 1, k);
        }
        
    }
}


///<--------Ordenamiento------->
//Selection Sort
template <class Type>
void ManejadorArreglosGenerico<Type>::selectionSort(){//Busca el minnimo y los va ponindo al principio
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
	int j;
	for (int i = 1; i < tam; i++) {
		j = i;
		while (j>0 && vec[j-1] > vec[j]) {
			cout << "while" << endl;
			swap(j, j-1);
			print();
			j--;
		}
		cout <<endl;
	}
}

//Bubble Sort
template <class Type>
void ManejadorArreglosGenerico<Type>::bubbleSort() {//Los numeros más altos se van acomodando hasta arriba, se van comparando para encontrar al max
	bool bandera;//Indica si hubo un cambio
	int subArray = tam-1;
	do {
		bandera = false;

		for (int i = 0; i < subArray ; i++) {
			if (vec[i] > vec[i+1]) {
				bandera = true;

				swap(i,i+1);

				print();
			}
		}
		subArray--;

	} while (bandera);

	//if swap, si bandera es false cuando acabe, entonces se acaba el while
	bandera = true;
}

///<---- QuickSort y MergeSort reciben arreglo------>
//Merge Sort
template <class Type>
void ManejadorArreglosGenerico<Type>::mergeSort(vector <Type> v, int n) {
    if(v == 1){//
        return v;
    }
    
    //Calcular mitad
    int mitad = n/2;//Si el numero es mpar c++ usa floor en una division de enteros
    
    //Declarar 2 arrays
    vector <Type> v1 = v[0 - mitad];
    vector <Type> v2 = v[mitad + 1 - n];
    
    //Ordenar 2 arrays de forma recursiva
    v1 = mergeSort(v1, mitad);
    v2 = mergeSort(v2, n - (mitad)-1);
    
    return merge(v1,v2);
}

template <class Type>
void ManejadorArreglosGenerico<Type>::merge(vector <Type> v1,vector <Type> v2) {
    vector <Type> vTemp;
    
    //Loop para unir los dos arrays mientras los dos tengan elementos
    while(!v1.empty() || !v2.empty()){//Mientras tengan elementos
        if(v1[0] > v2[0]){//Si el elemento en v1 es mayor al de v2
            //Se coloca el elemento de v2 en el vector temporal
            vTemp.push_back(v2[0]);
            //Se elimina el elemento de v2
            v2.erase(0);
        }else{//elemento en v2 es mayor
            //Se coloca el elemento de v1 en el vector temporal
            vTemp.push_back(v1[0]);
            //Se elimina el elemento de v1
            v1.erase(0);
        }
        
    }
    
    //Loop para unir arrays cuando solo queden elementos en v1
    while(!v1.empty()){
        //Se coloca el elemento de v1 en el vector temporal
        vTemp.push_back(v1[0]);
        //Se elimina el elemento de v1
        v1.erase(0);
    }
    
    //Loop para unir arrays cuando solo queden elementos en v2
    while(!v2.empty()){
        //Se coloca el elemento de v2 en el vector temporal
        vTemp.push_back(v2[0]);
        //Se elimina el elemento de v2
        v2.erase(0);
    }
    
    return vTemp;
}

//Quick Sort
template <class Type>
void ManejadorArreglosGenerico<Type>::quickSort(vector <Type> v, int lo, int hi) {
    
}

template <class Type>
int ManejadorArreglosGenerico<Type>::partition(vector <Type> v, int lo, int hi) {
    
}

///<---- QuickSort y MergeSort usan arreglo de ------>
//MergeSort    el problema de que merge sort use el mismo arreglo es que pierde la eficiencia y se vuelve O (n^2)
//MergeSort
template <class Type>
void ManejadorArreglosGenerico<Type>::mergeSort(int start, int end) {
    
}


//Quick Sort
template <class Type>
void ManejadorArreglosGenerico<Type>::quickSort(int lo, int hi) {
    
}

template <class Type>
int ManejadorArreglosGenerico<Type>::partition(int lo, int hi) {
    
}

int main(int argc, const char * argv[]) {
    vector <int> v = {90,70,00,50,30,10,60,80,20,40};
    
    ManejadorArreglosGenerico<int> *a = new  ManejadorArreglosGenerico<int>(v, 10);
    a->print();

    //a->mergeSort(v, 10);
    cout << 13/2 << endl;
	//Evitar que se cierre la consola en Visual studio
	int x;
	cin >> x;
	//Evitar que se cierre la consola en mac
    return 0;
}
