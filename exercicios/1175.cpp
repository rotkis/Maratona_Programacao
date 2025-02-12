#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int a[20], i, z;
	int n;
	for (i = 19; i >= 0; i--) {
		cin >> n;
		a[i] = n;

	}for (z = 0; z < 20; z++)
	{
	
		cout << "N[" << z << "] = " << a[z] << endl;
	}

}

