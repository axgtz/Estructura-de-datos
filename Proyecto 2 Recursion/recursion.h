//Roberto Alejandro Gutiérrez Guillén			A01019608			23/01/2017
#include <iostream>
#include <string>

using namespace std;

// recibe un string y regresa el string “limpio”
string limpiaString(string s) {
	
	if (s.size() <= 1 ) {
		return s;
	}else{
		if (s[0] == s[1]) {
			return limpiaString(s.substr(1));
		}
		else {
			return  s.substr(0,1) + limpiaString(s.substr(1));
		}
	}
}

// recibe un string s y un substring sub y regresa el número de veces que  
// aparece el substring en el string.
int cuantaSubstring(string s, string sub) {
	if (s.size()==0) {
		return 0;
	}else {
		if (s.find(sub) != s.npos) {
			return cuantaSubstring(s.erase(0, s.find(sub) + sub.size()), sub) + 1;
		}
		else{
			return 0;
		}
	}
}

// recibe un entero n y regresa la suma de sus dígitos
int sumaDigitos(int n) {
	if (n == 0) {
		return 0;
	}else{
		return n%10 + sumaDigitos(n / 10);
	}
}

// recibe un string s formado con paréntesis anidados y regresa true si los  
// paréntesis están correctamente anidados y false si no lo están.
bool anidacionCorrecta(string s) {
	if (s.size() == 0) {
		return true;
	}else {
		if (s.size() % 2 == 0) {
			if (s[0] == '(' && s[s.size()-1] == ')') {
				s.erase(0, 1);
				s.pop_back();
				return anidacionCorrecta(s);
			}
			return false;
		}
		return false;
	}
}
