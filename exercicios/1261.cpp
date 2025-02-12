#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main() {

	int words, texts;

	while (cin >> words) {
		cin >> texts;
		map<string, int> keys;
		
		string aa;
		int nn;
		for (int a = 0; a < words; a++) {
			cin >> aa >> nn;
			keys[aa] = nn;
		}

		vector<string> palavras; 

		int p = 0;
		string value;
		int soma = 0;
		while (cin >> value) {			
			if (value == ".") {
				cout << soma << endl;
				soma = 0;
				p++;
				if (p == texts) {
					break;
				}
			}

			if (keys.count(value) > 0) {
				soma += keys[value];
			}

		}
	}

}
