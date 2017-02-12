//Roberto Alejandro Gutiérrez Guillen   A01019608
#include <iostream>

using namespace std;

class Punto {
private:
	float CoordenadaX, CoordenadaY; // coordenada x y coordenada y del punto
public:
	Punto(float x, float y) { //inicializa las coordenadas del punto (x,y)
		CoordenadaY = y;
		CoordenadaX = x;
	}

	float ObtenerCoordenadaX() { // regresa la coordenada x del punto
		return CoordenadaX;
	}

	float ObtenerCoordenadaY() { // regresa la coordenada y del punto
		return CoordenadaY;
	}

	void ModificaX(float x) { // cambia el valor de la coordenada x del punto
		CoordenadaX = x;
	}

	void ModificaY(float y) { // cambia el valor de la coordenada y del punto
		CoordenadaY = y;
	}

	void ImprimeCoordenadas() { // imprime las coordenadas del punto
		cout << "Coordenada X: " << CoordenadaX << endl;
		cout << "Coordenada Y: " << CoordenadaY << endl;
	}
};


int main() {
	Punto p(1,1);
	p.ImprimeCoordenadas();
	p.ModificaX(3);
	p.ModificaY(2);
	cout << p.ObtenerCoordenadaX() << endl;
	cout << p.ObtenerCoordenadaY() << endl;

	system("pause");
	return 0;
}
