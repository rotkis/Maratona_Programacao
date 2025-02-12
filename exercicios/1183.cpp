#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	double M[12][12];
	string tipo;
	cin >> tipo;
	double soma = 0;

	for (int i = 0; i < 12; i++)
	{
		for (int a = 0; a < 12; a++) {
			cin >> M[i][a];
			if (a > i) {
				soma += M[i][a];
			}
		}
	}
	
	if (tipo == "S") {
		cout << fixed << setprecision(1) << soma << endl;
	}
	else if (tipo == "M") {
		soma/=66;
		cout << fixed << setprecision(1) << soma << endl;
	}
	


}

