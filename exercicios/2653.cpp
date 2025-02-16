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
using namespace std;
// and = &&
// or ||

int main() {
	list<string>joia;
	string a;
	
	int valor = 0;
	int tamanhoTotal = 0;
	const int limite = 1000000;
	while (cin >> a) {
		if (a == "0") {
			break;
		}

		auto it = find(joia.begin(), joia.end(), a);

		if (it == joia.end()) {
			
			joia.push_back(a);
			valor++;
		}

		
	}
	cout << valor << endl;
	
}



/*
vector<int> vet;
vector<int>::iterator veti;

for (int i = 0; i < 10; i++)
{
	cin >> vet[i];
	vet.push_back(5);
}
for (veti  = vet.begin(); veti != vet.end(); veti++)
{
	vet;
}

return 0;
*/
/*
	set
	list
	map
	vector
	deque
	queue
	staq*/
	/*
	list<int>cl;
	list<int>::iterator it_cl;
	int n;
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		cl.push_back(n);
	}
	cl.sort();
	for ( it_cl = cl.begin(); it_cl != cl.end(); it_cl++)
	{
		cout << *it_cl << endl;
	}
	return 0;
	*/
	/*
	* vet malloc(N*sizeof(float));
	* vet = new int[a];
	*
	int* vet;
	int a;
	cin >> a;

	vet = (int*)malloc(a * sizeof(int));


	for (int i = 0; i < a; i++)
	{
		vet[i] = i;
	}

	for (int i = 0; i < a; i++)
	{
		cout << vet[i] << endl;
	}


	*/
	/*
	set<int>CI;
	set<int>::iterator it_ci;

	int n;
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		CI.insert(n);
	}
	it_ci = CI.find(7);
	if (it_ci == CI.end()) {
		printf("não achou\n");
	}
	else {
		printf("achou!\n");
	}
	for (it_ci  = CI.begin(); it_ci  !=  CI.end(); it_ci ++)
	{
		cout << *it_ci << endl;
	}
	*/

	
	

