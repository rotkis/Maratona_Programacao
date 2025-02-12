#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main() {

	int v;
	while (cin >> v) {
		if (v == 0) {
			break;
		}

		queue<int> cards;
		queue<int> Dcards;
		
		for (int a = 1; a <= v; a++) {
			cards.push(a);
		}

		int c = 1;
		while (cards.size() > 1) {
			if (c % 2 != 0) {
				Dcards.push(cards.front());
				cards.pop();
			}
			else {
				cards.push(cards.front());
				cards.pop();
			}
			c++;
		}
		
		cout << "Discarded cards: ";
		while (!Dcards.empty())
		{
			if(Dcards.size() > 1) {
				cout << Dcards.front() << ", ";
				Dcards.pop();
			}
			else {
				cout << Dcards.front() << endl;
				Dcards.pop();
			}
		}
		cout << "Remaining card: " << cards.front() << endl;
		
	}

}

	
	

