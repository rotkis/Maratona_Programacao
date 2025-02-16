#include <iomanip>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>


using namespace std;

int main() {

	int time;
	while (cin >> time) {
		int total = 0;
		stack<string> face;
		char letter;
		string word = "";

		face.push("FACE");

		for (int a = 0; a < time; a++) {
			for (int z = 0; z < 4; z++) {
				cin >> letter;
				word.push_back(letter);
			}


			string wordR = word;
			reverse(wordR.begin(), wordR.end());

			if ( wordR == face.top()) {
				face.pop();
				total++;

				if (face.empty()) {
					face.push("FACE");
				}
			}
			else {
				face.push(word);
			}
			word.clear();
			wordR.clear();
		}
		cout << total << endl;

	}


}
