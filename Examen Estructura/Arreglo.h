//Roberto Alejandro Gutiérrez Guillén A01019608

#include <iostream>
#include <vector>

using namespace std;

class Arreglo {
private:
	int n = 100;
	int a[100];
public:
	Arreglo() {

	}
	int busquedaSecuencial(int inicio, int final, int k) {
		int res = -1;
		int i = inicio;
		for (i; i<final; i++) {
			if (k == a[i]) {
				res = i;
				return res;
			}
		}
	}

	int busquedaSaltandoN(int n, int k) {
		int res = -1, i;
		for (i = 0; i<n; i++) {
			if (k == a[i]) {
				res = i;
				return res;
			}
		}
	}
};

