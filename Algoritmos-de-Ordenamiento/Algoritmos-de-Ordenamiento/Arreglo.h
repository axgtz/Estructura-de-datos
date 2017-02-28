//  main.cpp
//  Algoritmos de Ordenamiento
//
//  Created by Alex Gutz on 2/13/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

//Librerias de lectura de datos
#include <fstream>
#include <sstream>

using namespace std;

class ManejadorArreglos {
    
private:
    int tam;
    int *vec;
    
public:
	ManejadorArreglos();
    
    ManejadorArreglos(int tam);
    
    ManejadorArreglos(string nombreArchivo);

    ManejadorArreglos(int *v, int tam);
    
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

    //Array Existente, el que esta en la clase
    void mergeSort(int lo, int hi);
    void merge(int lo, int mid, int hi);
    
};

ManejadorArreglos::ManejadorArreglos(){
    tam = 0;
    vec = {0};
}

ManejadorArreglos::ManejadorArreglos(int tam){
    this->tam = tam;
    vec = new int[tam];
}



//CONSTRUCTOR que hace lectura de datos, pero solo puede guardar int
ManejadorArreglos::ManejadorArreglos(string nombreArchivo) {
	lecturaDatos(nombreArchivo);	//lectura de datos para subir el contenido del text file al vector de la clase
}


//CONSTRUCTOR que recibe un vector

ManejadorArreglos::ManejadorArreglos(int* v, int tam) {
	this->tam = tam;
	vec = v;
}

//LECTURA DE DATOS
void ManejadorArreglos::lecturaDatos(string nombreArchivo) {
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
    
    vec = new int[tam];


    for (int i = 0;i<tam;i++) {
		archivo_entrada.getline(linea, sizeof(linea));
		vec[i] = stoi(linea);
	}

	archivo_entrada.close();
}

//SWAP
void ManejadorArreglos::swap(int a,int b){
    int temporal = vec[b];
    vec[b] = vec[a];
    vec[a] = temporal;
}

//PRINT
void ManejadorArreglos::print(){
    for(int i = 0 ; i < tam; i++){
        cout << vec[i];
		if (i + 1 != tam)//If es para que no imprima el guión después del último número 
			cout << " - ";
    }
    cout << endl;
}

///<--------Busquedas------->
//Busqueda Secuencial
int ManejadorArreglos::busquedaSecuencial(int a[], int n, int k) {
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
int ManejadorArreglos::busquedaBinaria(int a[], int primero, int ultimo, int k) {
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
void ManejadorArreglos::selectionSort(){//Busca el minnimo y los va ponindo al principio
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
void ManejadorArreglos::insertionSort() {
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
void ManejadorArreglos::bubbleSort() {//Los numeros más altos se van acomodando hasta arriba, se van comparando para encontrar al max
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

///<---- QuickSort y MergeSort usan arreglo de ------>
//MergeSort    el problema de que merge sort use el mismo arreglo es que pierde la eficiencia y se vuelve O (n^2)
//MergeSort
void ManejadorArreglos::mergeSort(int lo, int hi) {
    if(hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    
	mergeSort(lo, mid);// ordenar mitad izquierda
	mergeSort(mid+1, hi); // ordenar mitad derecha
    
    merge(lo, mid, hi);// Merge las dos mitades
}

//Merge
void ManejadorArreglos::merge(int lo, int mid, int hi) {
    int med = mid + 1;
    int newLow = lo;
    int tama = lo;
    
	int *arrTemp;

	arrTemp = new int[tam];

    while(newLow <= mid && med <= hi){
        if(vec[newLow] < vec[med]){
			arrTemp[tama] = vec[newLow];
            newLow++;
            tama++;
        }else{
			arrTemp[tama] = vec[med];
            med++;
            tama++;
        }
    }

    while(newLow <= mid){
		arrTemp[tama] = vec[newLow];
        newLow++;
        tama++;
    }

    while( med <= hi){
		arrTemp[tama] = vec[med];
        med++;
        tama++;
    }

    for(int d = lo; d < tama; d++){
        vec[d] = arrTemp[d];
    }
    print();
}

int main(int argc, const char * argv[]) {
    
    int v1[10] = {90,80,70,60,50,40,30,20,10,00};
    int v[11] = {100,90,70,00,50,30,10,60,80,20,40};
    
    ManejadorArreglos a(v ,11);

    a.mergeSort(0,10);
    
    cout << endl <<endl;
    a.print();
    //Evitar que se cierre la consola en Visual studio
	int x;
	cin >> x;
	//Evitar que se cierre la consola en mac
    return 0;
}
