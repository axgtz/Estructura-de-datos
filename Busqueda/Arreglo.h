//Roberto Alejandro Gutiérrez Guillén A01019608
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Arreglo {
private:
	int *arreglo;
	int tam;
public:
	//Constructor Vacio, solo inicializa el arreglo pero con cero elementos
	Arreglo() {
		arreglo = { 0 };
	}

	void lecturaDatos(string archivo) {  // Lee los datos de una archivo cuyo nombre recibe como parámetro
		ifstream archivo_entrada;

		string st = archivo + ".txt";

		archivo_entrada.open(st);

		if (archivo_entrada.fail()) {
			cout << "Error al abrir el archivo" << endl;
			arreglo[0] = { -1 };
		}
		//Se crea la variable temporal "linea" que es un arreglo de caracteres para poder extraer la información del
		//archivo por línea 
		char linea[128];

		//Usando la variable linea se extrae toda la primera linea del archivo de texto 
		archivo_entrada.getline(linea, sizeof(linea));

		//Se guarda el numero de numeros que va a contener el arreglo en el atributo de la clase entera "tam"
		tam = stoi(linea);

		//Se crea el arreglo con el tamaño que se leyo de la primera línea del archivo
		arreglo = new int[tam];

		for (int i = 0; i < tam; i++) {
			archivo_entrada.getline(linea, sizeof(linea));
			arreglo[i] = stoi(linea);
		}


		archivo_entrada.close();
	}

	// busca el elemento K en el arreglo, usando el algoritmo SECUENCIAL. Si lo  
	int busquedaSecuencial(int K) {  // encuentra devuelve su posición y en caso contrario regresa un ‐1.
		int i = 0;
		while (i < tam && arreglo[i] != K) 
			i++;
		
		if (i >= tam)
			i = -i;
		return i;
	}
	/*
	// busca el elemento K en el arreglo, usando el algoritmo BINARIO. Si lo  
	int busquedaBinaria(int inicio, int fin, int K){  // encuentra devuelve su posición y en caso contrario regresa un ‐1.
	int pos;
	int ini = 0;
	int fin = arreglo.size() -1;
	int mid = (ini+fin)/2;

	while ( ini <= fin && arreglo[mid] != K ){
	if (arreglo[mid] < K)
	fin = mid-1;
	else
	ini = mid+1;
	mid = (ini+fin)/2;
	}
	if ( ini > fin)
	pos = -ini-1;
	else
	pos = mid;
	return pos;
	}
	};

	public static<T extends Comparable<T>> int busquedaSecOrdenada(T[] a, int n, T x){
	int i=0;
	while (i<n && a[i].compareTo(x)<0){
	i++;
	}
	if (i>=n || a[i].compareTo(x)!=0)
	i=-i-1;
	return i;
	}
	public static<T extends Comparable<T>> int busquedaBinaria(T []a, int n, T x){
	int pos;
	int posini = 0;
	int posfin = n-1;
	int mitad = (posini+posfin)/2;

	while ( posini <= posfin && !a[mitad].equals(x) ){

	if (a[mitad].compareTo(x)>0 )
	posfin = mitad-1;
	else
	posini = mitad+1;
	mitad = (posini+posfin)/2;
	}
	if ( posini > posfin)
	pos = -posini-1;
	else
	pos = mitad;
	return pos;

	}
	*/
};
 