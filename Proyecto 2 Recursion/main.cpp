#include "recursion.h"

using namespace std;

int main() {
	//string s = "()()";
	//cout << sumaDigitos(123456789) << endl;
	//cout << "anidacion res: " << anidacionCorrecta(s) << endl;
	string s = "aaabbbccdd";
	string sub = "x";
	//cout << limpiaString(s) << endl;
	//cout << s.substr(0, 1) << ":0,1   1: "<< s.substr(1) << endl;
	//cout << " 1: " << s.substr(1) << endl;
	//cout << s.find(sub) << endl;
	cout << cuantaSubstring(s, sub) << endl;

	system("pause");
}
