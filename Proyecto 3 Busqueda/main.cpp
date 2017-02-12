//Roberto Alejandro Gutiérrez Guillén A01019608
#include "Arreglo.h"

using namespace std;

int main() {
	Arreglo a;
	a.lecturaDatos("nombre");
	int y = 0;
	while (y != -1) {
		cin >> y;
		cout << "Sec: " << a.busquedaSecuencial(y) << endl;
		cout << "Bin: " << a.busquedaBinaria(0, 9, y) << endl;
	}
	int x;
	cin >> x;
}



