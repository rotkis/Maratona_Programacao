#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// and = &&
// or ||
int main() {

	int n[100][100];
	
	while (true)
	{
		int linha, coluna, k = 1, m = 1;
		cin >> linha;
		if (linha == 0) break;
		for (int i = 0; i < linha; i++)
		{
			for (int j = 0; j < linha; j++)
			{
				m = abs(i - j) + 1;
				n[i][j] = m;
				
			}
		}
		int big = n[0][0];
		for (int i = 0; i < linha; i++) {
			for (int j = 0; j < linha; j++) {
				if (big < n[i][j]) {
					big = n[i][j];
				}
			}
		}
		string num1 = to_string(big);

		int value = num1.size()+3;
		for (int i = 0; i < linha; i++)
		{
			for (int j = 0; j < linha; j++)
			{
				if (j < linha -1) {
					cout << setw(3) << n[i][j] << " ";
				}
				else {
					cout << setw(3) << n[i][j];
				}
				
			}
			cout << endl;
		}
		cout << endl;
	}
}

