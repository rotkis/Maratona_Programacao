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
#include <deque>

using namespace std;
// and = &&
// or ||
int calls = 0;
int cont = 0;
long long int fib(int num) {
	cont++;
	if (num == 0 || num == 1) {
		if (num == 1) {
			calls++; 
		}
		return 1;
	}

	else {
		return fib(num - 1) + fib(num-2);
	}
}
int main() {
	int qtd; 
	while (cin >> qtd) {
		int a;
		for (int i = 0; i < qtd; i++)
		{
			cin >> a;
			fib(a);
			printf("fib(%d) = %d calls = %d\n",a,cont-1,calls);
			calls = 0;
			cont = 0;
		}
	}
	return 0;
}	







