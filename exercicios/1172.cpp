#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int a[10], i, n;
	for (i = 0; i < 10; i++) {
		cin >> n;
		a[i] = n;
		if (n < 1) {
			n = 1;
		}
		cout << "X[" << i << "] = " << n << endl;
	}

}

