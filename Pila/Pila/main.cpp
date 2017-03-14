//Roberto Alejandro Gutierrez Guillen			A01019608
#include "Pila.h"
#include <iostream>

using namespace std;

int main() {
	Pila p(4);

	p.push(2);
	p.push(3);
	p.push(4);
	p.push(5);
	cout << p.pilaLlena() << endl;
	cout << p.pilaVacia() << endl;
	p.imprimePila();

	int h;
	p.pop(h);
	p.pop(h);

	p.imprimePila();

	p.pop(h);
	p.pop(h);
	cout << p.pilaLlena() << endl;
	cout << p.pilaVacia() << endl;

	int x;
	cin >> x;
	return 0;
}
