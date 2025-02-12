#include	 <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// and = &&
// or ||
int main() {

	int n[70][70];
	int linha, coluna, k = 1, m = 2, g = 3;
	while (cin >> linha)
	{


		for (int i = 0; i < linha; i++)
		{
			for (int j = 0; j < linha; j++)
			{
				if (j + i == linha - 1) {
					n[i][j] = m;
				}
				else if (j == i) {
					n[i][j] = k;
				}
				else
				{
					n[i][j] = g;
				}
			}
		}
		for (int i = 0; i < linha; i++)
		{
			for (int j = 0; j < linha; j++)
			{
				cout << n[i][j];
			}
			cout << endl;
		}
	}
}

