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

	int val = 0;

	while (cin >> val) {


		multiset<int> n;

		int a, b;
		for (int i = 0; i < val; i++) {
			cin >> a;
			cin >> b;
			for (int j = a; j <= b; j++) {
				n.insert(j);
			}
		}
		int v = 0;
		cin >> v;

		int count1 = 0;
		int count2 = 0;
		int posF = 0;
		int posI = 0;
		for (const auto& e : n) {
			if (e == v) {
				count2 += 1;
				posF = count1;
			}
			count1 += 1;
		}

		if (count2 == 0) {
			printf("%d not found\n", v);
		}
		else if (count2 == 1) {
			printf("%d found from %d to %d\n", v, posF, posF);
		}
		else {
			posI = posF - (count2 - 1);
			printf("%d found from %d to %d\n", v, posI, posF);
		}


	}

}


	
	

