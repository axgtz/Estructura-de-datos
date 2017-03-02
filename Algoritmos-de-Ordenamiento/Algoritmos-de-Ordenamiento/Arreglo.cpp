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

class Arreglo {
    
private:
    int tam;
    int *vec;
    
public:
	Arreglo();
    
	Arreglo(int tam);
    
	Arreglo(string nombreArchivo);

	Arreglo(int *v, int tam);
    
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


    void mergeSort(int lo, int hi);
    void merge(int lo, int mid, int hi);

	void quickSort(int lo, int hi);
	int particion(int lo, int hi);//Regresa el indice donde quedo el pivote
    
};

///<---------CONSTRUCTOR----------> 
//CONSTRUCTOR 
Arreglo::Arreglo(){
    tam = 0;
    vec = {0};
}

//CONSTRUCTOR 
Arreglo::Arreglo(int tam){
    this->tam = tam;
    vec = new int[tam];
}

//CONSTRUCTOR que hace lectura de datos, pero solo puede guardar int
Arreglo::Arreglo(string nombreArchivo) {
	lecturaDatos(nombreArchivo);	//lectura de datos para subir el contenido del text file al vector de la clase
}

//CONSTRUCTOR que recibe un vector
Arreglo::Arreglo(int* v, int tam) {
	this->tam = tam;
	vec = v;
}


//LECTURA DE DATOS
void Arreglo::lecturaDatos(string nombreArchivo) {
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
void Arreglo::swap(int a,int b){
    int temporal = vec[b];
    vec[b] = vec[a];
    vec[a] = temporal;
}

//PRINT
void Arreglo::print(){
    for(int i = 0 ; i < tam; i++){
        cout << vec[i];
		if (i + 1 != tam)//If es para que no imprima el guión después del último número 
			cout << " - ";
    }
    cout << endl;
}

///<--------Busquedas------->
//Busqueda Secuencial
int Arreglo::busquedaSecuencial(int a[], int n, int k) {
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
int Arreglo::busquedaBinaria(int a[], int primero, int ultimo, int k) {
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
void Arreglo::selectionSort(){//Busca el minnimo y los va ponindo al principio
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
void Arreglo::insertionSort() {
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
void Arreglo::bubbleSort() {//Los numeros más altos se van acomodando hasta arriba, se van comparando para encontrar al max
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
void Arreglo::mergeSort(int lo, int hi) {
    if(hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    
	mergeSort(lo, mid);// ordenar mitad izquierda
	mergeSort(mid+1, hi); // ordenar mitad derecha
    
    merge(lo, mid, hi);// Merge las dos mitades
}

//Merge
void Arreglo::merge(int lo, int mid, int hi) {
	//Se crean varaiables para evitar cambiar los parametros que sirven de referencia
	//para evitar accesar partes del array que no existen
    int med = mid + 1;
    int newLow = lo;
    int tama = lo;
    
	//Se crea arreglo temporal para evitar que el rendimiento del algoritmo baje
	int *arrTemp;
	arrTemp = new int[tam];

	//Mientras las dos mitades contengan datos
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

	//Mientras la primera mitad contenga datos, parte izquierda
    while(newLow <= mid){
		arrTemp[tama] = vec[newLow];
        newLow++;
        tama++;
    }

	//Mientras la segunda mitad contenga datos, parte derecha
    while( med <= hi){
		arrTemp[tama] = vec[med];
        med++;
        tama++;
    }

	//Se pasan los datos del arreglo temporal al de la clase
    for(int d = lo; d < tama; d++){
        vec[d] = arrTemp[d];
    }
	//Se imprime despues de cada iteracion de la funcion merge
    print();
}

void  Arreglo::quickSort(int lo, int hi) {//La Api solo especifica quickSort, no particion
	// j = pivote
}

int  Arreglo::particion(int lo, int hi) {//Regresa el indice donde quedo el pivote	

}

int main(int argc, const char * argv[]) {

	Arreglo a("texto");

	a.mergeSort(0, 9);

	cout << endl << endl;
	a.print();
	//Evitar que se cierre la conpsola en Visual studio
	int x;
	cin >> x;
	//Evitar que se cierre la consola en mac
	return 0;
}