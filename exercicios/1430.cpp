#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {

	string composicao;
	while (cin >> composicao) {
		if (composicao == "*") {
			break;
		}
		
		
		istringstream isscomp(composicao);
		string interval;

		vector<string> compInterval;
		int total = 0;
		while (getline(isscomp, interval, '/')) {
			
			double soma = 0;
			if (interval != "") {
				compInterval.push_back(interval);

				vector<char> vinterval(interval.begin(), interval.end());
				for (const char& l : vinterval) {
					if (l == 'W') {
						soma += 1;
					}
					else if (l == 'H') {
						soma += 1.00/2.00;
					}
					else if (l == 'Q') {
						soma += 1.00/4;
					}
					else if (l == 'E') {
						soma += 1.00/8;
					}
					else if (l == 'S') {
						soma += 1.00/16;
					}else if (l == 'T') {
						soma += 1.00/32;
					}else if (l == 'X') {
						soma += 1.00/64;
					}
				}
				if (soma == 1) {
					total += 1;
				}

			}

		}
		cout << total << endl;
		
		/*
		for (const string &l : compInterval) {
			cout << l << endl;
		}
		*/
		
		
	}

}
