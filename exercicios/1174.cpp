#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int a[100], i;
	double n;
	for (i = 0; i < 100; i++) {
		cin >> n;
		a[i] = n;
		if ( n <= 10) {
			cout << fixed << setprecision(1) << "A[" << i << "] = " << n << endl;
		}
		
	}

}

