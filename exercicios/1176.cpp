#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int  i, z;
	int n;
	unsigned long long a[61];
	a[0] = 0;
	a[1] = 1;
	for (i = 2; i < 61; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	cin >> n;
	while (n--)
	{
		cin >> z;
		cout << "Fib(" << z << ") = " << a[z] << endl;
	}

	
}

