//Roberto Alejandro Gutiérrez Guillén A01019608
#include "Arreglo.h"

using namespace std;

int main(){
	Arreglo a;
	a.lecturaDatos("nombre");
	cout << "Sec: " << a.busquedaSecuencial(-1) << endl;
	cout << "Bin: " << a.busquedaBinaria(0,9,-1) << endl;

	int x;
	cin >> x;
}
