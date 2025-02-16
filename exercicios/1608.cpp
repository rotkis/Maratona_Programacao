#include <iomanip>
#include <algorithm>
#include <iostream>
#include <istream>
#include <unordered_map>
#include <set>
#include <map>
#include <vector>


using namespace std;

int main() {


	int quantidadeTest;
	
	while (cin >> quantidadeTest) {
		for (int i = 0; i < quantidadeTest; i++) {

			int money, ingredientes, tiposBolos;
		
			cin >> money >> ingredientes >> tiposBolos;
			
			vector<int>precos(ingredientes);
			
			for (int i = 0; i < ingredientes; i++){

				cin >> precos[i];

			}
		
			vector<int>bolos;

			for (int x = 0; x < tiposBolos; x++) {
			
				int numeroIngredientes, precoBolo = 0;
			
				cin >> numeroIngredientes;

				for (int j = 0; j < numeroIngredientes; j++) {
				
					int indiceIngrediente, quantidadeIngrediente;
					cin >> indiceIngrediente >> quantidadeIngrediente;
					precoBolo += quantidadeIngrediente * precos[indiceIngrediente];
					
				}
				bolos.push_back(precoBolo);
			}

			int maior = 0;
			
			for (int x = 0; x < bolos.size(); x++) {
				
				int final = 0;
				final = money / bolos[x];
				if (final > maior) {
					maior = final;
				}
			
			}

			cout << maior << endl;

		}
	}
    return 0;
}
