#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <cstdlib>
#include <list>
#include <map>
#include <sstream>
#include <stack>
#include <string>
using namespace std;
// and = &&
// or ||

int main() {

	string rna;

	while (cin >> rna) {

		string linha = "";

		int cont = 0;
		for (const auto& g : rna)
		{
			linha.push_back(g);
		}

		for (int b = 0; b < linha.size(); b++) {

			if ((linha[b] == 'S' && linha[b+1] == 'B')||(linha[b+1] == 'S' && linha[b] == 'B')) {
				cont++;
				linha.erase(b, 1);
				linha.erase(b, 1);
				b = -1;
			}
			else if ((linha[b] == 'C' && linha[b + 1] == 'F')|| (linha[b+1] == 'C' && linha[b] == 'F'))
			{
				cont++;
				
				linha.erase(b, 1);
				linha.erase(b, 1);
				b = -1;
			}
			
		}
		
		cout << cont << endl;
	}



}






