#include <iostream>
#include "Arbol.hpp"

using namespace std;
int main() {
	Arbol uno;
	uno.CrearArbol(uno.RegresaRaiz());
	cout<<"\n";
	uno.Preorden(uno.RegresaRaiz());
	cout<<"\n";
	uno.Inorden(uno.RegresaRaiz());
	cout<<"\n";
	uno.Postorden(uno.RegresaRaiz());
	
}