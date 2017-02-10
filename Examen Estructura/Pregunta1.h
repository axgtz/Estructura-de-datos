//Roberto Alejandro Gutiérrez Guillén A01019608

#include <iostream>

using namespace std;

class Rectangulo {
private:
	int base, altura;
public:
	Rectangulo() {
		base = 0;
		altura = 0;
	}

	int calcArea() {
		return  base * altura;
	}

	int calcPerimetro() {
		return (base*2) + (altura * 2);
	}

	void setAltura(int a) {
		altura = a;
	}

	void setBase(int b) {
		base = b;
	}
};

