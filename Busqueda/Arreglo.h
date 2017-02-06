//Roberto Alejandro Gutiérrez Guillén A01019608
#include <iostream>
#include <string>

using namespace std;

class Arreglo(){
private:
  //int a[];
public:
	 Arreglo();
  // Lee los datos de una archivo cuyo nombre recibe como parámetro
  void lecturaDatos(string archivo){

  }

  // busca el elemento K en el arreglo, usando el algoritmo SECUENCIAL. Si lo  
  // encuentra devuelve su posición y en caso contrario regresa un ‐1.
  int busquedaSecuencial(int K){
    return 1;
  }


  // busca el elemento K en el arreglo, usando el algoritmo BINARIO. Si lo  
  // encuentra devuelve su posición y en caso contrario regresa un ‐1.
  int busquedaBinaria(int inicio, int fin, int K){
    int pos;
    int ini = 0;
    int fin = n-1;
    int mid = (ini+fin)/2;

     while ( ini <= fin && a[mid] != K ){
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
}
/*
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
