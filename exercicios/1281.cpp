#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int main() {

	int time;
	while (cin >> time) {

		for (int a = 0; a < time; a++) {
			
			map<string, float> loja;
			
			int items;
			cin >> items;

			for (int b = 0; b < items; b++) {
				
				string name;
				float preco;
				cin >> name >> preco;

				loja.insert({ name, preco });

			}
			int compras;
			cin >> compras;
			double soma = 0;
			for (int c = 0; c < compras; c++) {

				string name;
				int unid;
				cin >> name >> unid;

				double vp = loja[name] * unid;
				soma += vp;
			}
			cout << fixed << setprecision(2) << "R$ " << soma << endl;

		}

	}

}
