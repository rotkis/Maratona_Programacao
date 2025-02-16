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
#include <climits>
#include <queue>
#include <functional>
#define INF INT_MAX
#define MAIOR 101
using namespace std;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<int> si;
typedef queue<int> qi;
typedef vector<vi> gra;
typedef vector<vc> matriz;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;
gra grafo(MAIOR);
vi visitados(MAIOR, 0);
// and = &&
// or = ||
struct camisa {
    char tam;
    string cor;
    string nome;
};
bool comparaCamisas(const camisa& a, const camisa& b) {
    if (a.cor != b.cor) {
        return a.cor < b.cor;
    }
    if (a.tam != b.tam) {
        return a.tam > b.tam;
    }
    if (a.nome != b.nome) {
        return a.nome < b.nome;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int vezes;
    bool pula = false; 
    while (cin >> vezes) {
        if (vezes == 0) { 
        
            break; 
        }
        vector<camisa> camisas(vezes);
        int cont = 0;
        if (pula){
            cout << endl;
        }
        for (int i = 0; i < vezes; i++) {
            cin.ignore();
            getline(cin, camisas[i].nome);
            cin >> camisas[i].cor >> camisas[i].tam;
        }

        sort(camisas.begin(), camisas.end(), comparaCamisas);
        for (int i = 0; i < camisas.size(); i++)
        {
            cout << camisas[i].cor << " " << camisas[i].tam << " " << camisas[i].nome << endl;
        }
        pula = true;
        camisas.clear();
    }
    return 0;
}
