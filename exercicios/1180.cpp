#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int valorN;
	cin >> valorN;
	int x[1000];
	int input;
	int a = 0;
	int posi;
	for (int i = 0; i < valorN; i++)
	{
		cin >> input;
		if (i == 0) {
			a = input;

		}
		if (input < a) {
			a = input;

			posi = i;
		}
	}
	cout << "Menor valor: " << a << endl << "Posicao: " << posi << endl;
}

