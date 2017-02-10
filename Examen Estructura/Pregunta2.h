//Roberto Alejandro Gutiérrez Guillén A01019608

#include <iostream>

using namespace std;

bool palindromo(string pal) {
	if (pal.size() <= 1)
		return true;
	else {
		if ((pal.size() % 2 )== 0) {
			if (pal[0] == pal[pal.size() - 1]) {
				pal.pop_back();
				pal.erase(0, 1);
				return palindromo(pal);
			}
			return false;
		}
	}
}