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
	int atri, qtd_m, qtd_l, atibuto;
	int call_m, call_l;
	while (cin >> atri)
	{


		
		vector<vector<int>>mar;
		vector<vector<int>>leo;
		cin >> qtd_m >> qtd_l;
		for (int i = 0; i < qtd_m; i++)
		{
			vector<int>linha_m;
			for (int j = 0; j < atri; j++)
			{
				int atri_m;
				cin >> atri_m;
				linha_m.push_back(atri_m);
			}
			mar.push_back(linha_m);
		}
		for (int i = 0; i < qtd_l; i++)
		{
			vector<int>linha_l;
			for (int j = 0; j < atri; j++)
			{
				int atri_l;
				cin >> atri_l;
				linha_l.push_back(atri_l);
			}
			leo.push_back(linha_l);
		}
		cin >> call_m >> call_l >> atibuto;
		if (mar[call_m - 1][atibuto - 1] > leo[call_l - 1][atibuto - 1]) {
			cout << "Marcos" << endl;
			
		}
		else if (mar[call_m - 1][atibuto - 1] < leo[call_l - 1][atibuto - 1]) {
			cout << "Leonardo" << endl;
			
		}
		else if (mar[call_m - 1][atibuto - 1] == leo[call_l - 1][atibuto - 1]) {

			cout << "Empate" << endl;
			
		}



	}
//	int n, q;
//
//	while (cin >> n >> q) {
	//	vector<int>notas(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> notas[i];

	//	}
//		sort(notas.begin(), notas.end());
	//	reverse(notas.begin(), notas.end());
//		for (int i = 0; i < q; i++)
	//	{
	//		int posicao;
	//		cin >> posicao;
	//		cout << notas[posicao - 1] << endl;
	//	}

	//}
	


}

