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

	while (cin >> qtdiamante) {
		for (int i = 0; i < qtdiamante; i++) {
			string areia;
			
			cin >> areia;
			
			string linha = "";
			for (const char& g: areia){
				if (g == '<' || g == '>') {
					linha.push_back(g);
				}

			}
			
			
			int cont = 0;
		
				for (int b = 0; b < linha.size();b++) {
					if (linha[b] == '<') {
						
						for (int c = b+1; c < linha.size(); c++) {
							if (linha[c] == '>')
							{
								
								cont++;
								linha.erase(c, 1);
								break;
							}
						}
					}
				}
			cout << cont << endl;

			}
		}
		
	}



	
	

