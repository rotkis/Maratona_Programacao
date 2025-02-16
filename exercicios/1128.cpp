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
#define MAIOR 2001
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef queue<int> qi;
typedef vector<vi> Graph;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;

Graph grafo(MAIOR);
vi visitados(MAIOR, 0);
void dfs(int origem) {
    visitados[origem] = 1;
    for (int i = 0; i < grafo[origem].size(); i++)
    {
        if (visitados[grafo[origem][i]] == 0) {
            dfs(grafo[origem][i]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int interseccao, ruas;
    while (cin >> interseccao >> ruas) {
        if (interseccao == ruas && ruas == 0) {
            break;
        }
        grafo.resize(interseccao);
        for (int i = 0; i < ruas; i++) {
            int origem, destino, mao;
            cin >> origem >> destino >> mao;
            if (mao == 2) {
                grafo[origem - 1].push_back(destino - 1);
                grafo[destino - 1].push_back(origem - 1);
            }
            else
            {
                grafo[origem - 1].push_back(destino - 1);
            }
        }
        bool connect = true;
        for (int i = 0; i < grafo.size(); i++)
        {
        visitados.assign(interseccao, 0);
        dfs(i);
        for (int j = 0; j < visitados.size(); j++) {
            if (visitados[j] == 0) {
                connect = false;
            }
        }
        }

        if (connect) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
        grafo.clear();
        visitados.clear();
    }

    
    return 0;
}
