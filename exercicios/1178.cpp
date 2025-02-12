#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;
// and = &&
// or ||
int main() {
	int n[100] ;
	double x;
	cin >> x;
	cout << fixed << setprecision(4) << "N[" << 0 << "] = " << x << endl;
	for (int i = 1; i < 100; i++)
	{
		 x /= 2;
		cout << fixed << setprecision(4) << "N[" << i << "] = " << x << endl;
			
	}

}

