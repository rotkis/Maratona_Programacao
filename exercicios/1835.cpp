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
#define INF INT_MAX
#define MAIOR 101
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef vector<vi> Graph;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;

Graph grafo(MAIOR);

vi visitados;
int ans;
void dfs(int rotulo) {
    visitados[rotulo] = 1;

    for (int i = 0; i < grafo[rotulo].size(); i++) {
        if (visitados[grafo[rotulo][i]] == 0) {
            dfs(grafo[rotulo][i]);
        }
    }
}

int main() {
    int testes;
    cin >> testes;
    for (int i = 0; i < testes; i++) {
        int pontos, estradas;
        cin >> pontos >> estradas;
        grafo.resize(pontos);
        visitados.resize(pontos, 0);
        for (int j = 0; j < estradas; j++) {
            int origem, destino;
            cin >> origem >> destino;
            grafo[origem-1].push_back(destino-1);
            grafo[destino-1].push_back(origem-1);
        }
        cout << "Caso #" << i + 1 << ": ";
        ans = 0;
        for (int j = 0; j < pontos; j++) {
            if (visitados[j] == 0) {
                dfs(j);
                ans++;
            }
        }
   
        if (ans  - 1 == 0) {
            cout << "a promessa foi cumprida" << endl;
        }
        else {
            cout << "ainda falta(m) " << ans - 1 << " estrada(s)" << endl;
        }
        grafo.clear();
        visitados.clear();

    }
    return 0;
}
