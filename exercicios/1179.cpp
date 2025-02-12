#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int p[5], im[5];
	int aux1 =0 , aux2=0 ;
	int t;

	for (int i = 0; i < 15; i++) {
		cin >> t;

		if (t % 2 == 0) {
			p[aux2] = t;
			aux2++;

		}
		 if (t % 2 != 0) {
			im[aux1] = t;
			aux1++;
		}
		 if (aux2 ==5)
		 {
			 for (int i = 0; i < 5; i++)
			 {
				 cout << "par[" << i << "] = " << p[i] << endl;
			 }
			 aux2 = 0;
		 }
		 if (aux1 == 5)
		 {
			 for (int i = 0; i < 5; i++)
			 {
				 cout << "impar[" << i << "] = " << im[i] << endl;
			 }
			 aux1 = 0;
		 }
	}
	for (int i = 0; i < aux1; i++)
	{
		cout << "impar[" << i << "] = " << im[i] << endl;
	}
	for (int i = 0; i < aux2; i++)
	{
		cout << "par[" << i << "] = " << p[i] << endl;
	}
}

