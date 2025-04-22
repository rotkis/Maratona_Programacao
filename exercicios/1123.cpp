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
#define MAIOR 251
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<int> si;
typedef queue<int> qi;
typedef vector<vector<pii>> grafoPii;
typedef vector<vi> grafoi;
typedef vector<vc> matriz;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vi dijkstra(int source, grafoPii &grafo) {
    vi distancias(grafo.size(), INT_MAX);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0 , source });
    distancias[source] = 0;
    while (!pq.empty()) {
        int vertice_saida = pq.top().second;
        pq.pop();
        for (auto i : grafo[vertice_saida])
        {
            for (auto& p : grafo[vertice_saida]) {
                int vertice_atual = p.first; int weight = p.second;
                if (distancias[vertice_atual] > distancias[vertice_saida] + weight) {
                    distancias[vertice_atual] = distancias[vertice_saida] + weight;
                    pq.push({ distancias[vertice_atual] , vertice_atual });
                }
            }
        }
    }
    return distancias;
}

int main() {
    int cidades, estradas, rota, conserto;
    while (cin >> cidades >> estradas >> rota >> conserto) {
        if (cidades == 0 && estradas == cidades && rota == estradas && rota == conserto) break;
        grafoPii grafo(MAIOR);
        int origem, destino, peso;
        for (int i = 0; i < estradas; i++) {
            cin >> origem >> destino >> peso;
            if (origem >= rota && destino >= rota) {
                grafo[origem].push_back({ destino ,peso });
                grafo[destino].push_back({ origem ,peso });
            }
			if (origem >= rota && destino < rota)
			{
                grafo[origem].push_back({ destino ,peso });
			}
            if (origem < rota && destino >= rota) {
                grafo[destino].push_back({ origem ,peso });
            }if (origem < rota && destino < rota && abs(origem - destino) == 1) {
                grafo[origem].push_back({ destino ,peso });
                grafo[destino].push_back({ origem ,peso });
            }
        }
        
       vi distancias = dijkstra(conserto,grafo);
       cout << distancias[rota -1] << endl;
    }

    return 0;
}


