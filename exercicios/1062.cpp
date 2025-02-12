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
	int vagoes;
	while (cin >> vagoes) {
		if (vagoes == 0) {
			break;

		}
	
		
	
		while (true)
		{
			stack<int>resposta;
			resposta.push(0);
			for (int i = 1; i <= vagoes; i++) {
				resposta.push(i);
			}
			stack<int>comparacao;
			comparacao.push(0);
			int inserir = 0;
			for (int i = 0; i < vagoes; i++) {
				cin >> inserir;
				if (inserir == 0) {
					break;
				}
				comparacao.push(inserir);
			}
			if (inserir == 0) {
			    cout << endl;
				break;
			}
			stack<int>espera;
			espera.push(0);
				while (true)
			{
				if (resposta.top() == comparacao.top() || espera.top() == resposta.top()) {
					if (espera.top() == resposta.top())
					{
						if (resposta.top() == 0) {
							break;
						}
						espera.pop();
						resposta.pop();

					}
					else {
						if (resposta.top() == 0) {
							break;
						}
						comparacao.pop();
						resposta.pop();

					}

				}
				else {

					espera.push(comparacao.top());
					if (comparacao.top() == 0) {
						break;
					}
					comparacao.pop();
				}
			}
			if (resposta.top() == 0) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		
		

	}
}






