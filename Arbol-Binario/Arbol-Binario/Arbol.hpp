//Por Emiliano Abascal Gurria
#include <iostream>
#ifndef Arbol_HPP
#define Arbol_HPP
using namespace std;
int cont = 0;

class nodo {
	private:
		int dato;
		nodo *hijoIzquierdo;
		nodo *hijoDerecho;
		
	public:
		nodo();
		int RegresaDato();
		friend class Arbol;
		
};

nodo::nodo(){
	hijoDerecho = NULL;
	hijoIzquierdo =  NULL;
}

int nodo::RegresaDato(){
	return dato;
}

class Arbol{
	private:
		nodo *raiz;
	public:
		Arbol();
		void CrearArbol(nodo *);
		void Preorden(nodo *);
		void Inorden(nodo *);
		void Postorden(nodo *);
		nodo *RegresaRaiz();
};

Arbol::Arbol(){
	raiz = NULL;
}

void Arbol::Preorden(nodo *pointer){
	if (pointer){
		cout<<pointer->dato<<" ";
		Preorden(pointer->hijoIzquierdo);
		Preorden(pointer->hijoDerecho);
	}
}
void Arbol::Inorden(nodo *pointer){
	if (pointer){
		Inorden(pointer->hijoIzquierdo);
		cout<<pointer->dato<<" ";
		Inorden(pointer->hijoDerecho);
	}
}
void Arbol::Postorden(nodo *pointer){
	if (pointer){
		Postorden(pointer->hijoIzquierdo);
		Postorden(pointer->hijoDerecho);
		cout<<pointer->dato<<" ";
	}
}

void Arbol::CrearArbol(nodo *pointer){
	char r;
	char r2;
	pointer = new nodo;
	if (cont == 0){
		cout<<"Cual es el valor de la raiz?: ";
		cin>>pointer->dato;
		cont = 1;
		cout<<"\n¿"<<pointer->dato<<" Tiene un hijo izquierdo (S/N)?: ";
		cin >> r;
		if(r == 's' || r == 'S'){
			CrearArbol(pointer->hijoIzquierdo);
			pointer->hijoIzquierdo=raiz;
		}
		cout<<"\n¿"<<pointer->dato<<" Tiene un hijo Derecho (S/N): ";
		cin>>r2;
		if(r2 == 's' || r2 == 'S'){
			CrearArbol(pointer -> hijoDerecho);
			pointer -> hijoDerecho = raiz;
		}
	}else{
		cout<<"¿Cual es el valor de este hijo?: ";
		cin>>pointer->dato;
		cout<<"\n¿"<<pointer->dato<<" Tiene hijo izquierdo (S/N)?: ";
		cin >> r;
		if(r == 's' || r == 'S'){
			CrearArbol(pointer->hijoIzquierdo);
			pointer->hijoIzquierdo=raiz;
		}
		cout<<"\n¿"<<pointer->dato<<" Tiene hijo Derecho (S/N): ";
		cin>>r2;
		if(r2 == 's' || r2 == 'S'){
			CrearArbol(pointer -> hijoDerecho);
			pointer -> hijoDerecho = raiz;
		}
	}
	 
	raiz = pointer;
	
}

nodo *Arbol::RegresaRaiz(){
	return raiz;
}
#endif