#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int a[1000], i, z;
	int n;
	cin >> n;
	for (i = 0; i < 999; i++) {
		
		a[i] = n;
		for (z = 0; z < n; z++ ,i++)
		{
			cout << "N[" << i << "] = " << z << endl;
			if (i == 999) {
				break;
			}
		}
		i--;
	}

}

