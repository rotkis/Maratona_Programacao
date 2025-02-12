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

	int qtdiamante;



	string areia;

	while (cin >> areia) {



		string linha = "";
		for (const char& g : areia) {
			if (g == '(' || g == ')') {
				linha.push_back(g);
			}

		}


		int cont = 0;

		for (int b = 0; b < linha.size(); b++) {
			
			if (linha[b] == '(') {
				
				for (int c = b + 1; c < linha.size(); c++) {
					if (linha[c] == ')')
					{
						linha.erase(c, 1);
						linha.erase(b, 1);
						b = -1;
						break;
						
					}
				}
			}
		}

		
		if (linha.empty()) {
			cout << "correct" << endl;
		}
		else
		{
			cout << "incorrect" << endl;
		}

	}

}






