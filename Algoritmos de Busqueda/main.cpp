//Roberto Alejandro Gutiérrez Guillén			A01019608			26/01/2017

#include <iostream>

using namespace std;


//
int busquedaSecuencial(int a[], int n, int k) {
	int res = -1, i;
	for (i = 0;i<n;i++) {
		if (k == a[i]) {
			res = i;
			return res;
		}
	}
}

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

int main() {
	int a [9] = {-3,-1,0,2,3,5,6,7,9};
	cout << busquedaBinaria(a,0,8,-2) << endl;
	system("pause");
}