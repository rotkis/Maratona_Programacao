#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int a[10], i, n;
	cin >> n;
	for (i = 0; i < 10; i++) {
		
		a[i] = n;
		
		cout << "N[" << i << "] = " << n << endl;
		n *= 2;
	}

}
