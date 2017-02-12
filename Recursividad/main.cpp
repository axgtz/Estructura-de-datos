//Robeto Alejandro Gutiérrez Guillén			A01019608

#include <iostream>
#include <string>

using namespace std;


int maxN(int a[], int n) {
	if (n == 1) {
		return a[0];
	}
	else {
		int max = a[0];
		if (max < a[n - 1]) {
			a[0] = a[n - 1];
		}
		return maxN(a, n - 1);
	}
}
/*
No sirve
int maxN(int a[], int n) {
	int max = a[0];
	if (n == 1) {
		return a[0];
	} else {

		if (max < a[n - 1]) {
			a[0] = a[n - 1];
			return maxN(a, n - 1);
		}
		return maxN(a, n - 1);
	}
}
No sirve
int numVoc(string s, int i) {
	
	if (s.size() == 0) {
		return s.size();
	}
	else {
		//int i = s.size() - 1;
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) {
			return numVoc(s,i - 1);
		}
		s.pop_back();
		return numVoc(s,i-1);
	}
}

*/

int multi(int a, int b) {
	if (b==0) {
		return 0;
	}
	else {
		return a + multi(a, b - 1);
	}
}

int fibo(int n){
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	else {
		cout << n << endl;
		return fibo(n-1) + fibo(n-2);
	}
}

//Recursión de Cola, con acumulador
int fact(int n, int acum){
	if (n==0) {
		return acum;
	}
	else {
		return fact(n-1,n*acum);
	}
}

//Recursión No-Cola
int fact(int n) {
	if (n==0) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}

int main() {
	
	int a[7] = { 10, 1, 2, 3, 4, 8, 9};
	int n = 7;
	cout << maxN(a, n) << endl;
	
	string s = "taquitos";
	//numVoc(s, s.size() - 1);
	

	cout << fibo(50) << endl;
	system("pause");
}
