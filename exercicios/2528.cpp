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
#define MAIOR 1001
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<int> si;
typedef queue<int> qi;
typedef vector<vector<pii>> gra;
typedef vector<vi> graph;
typedef vector<vc> matriz;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;



vi dijkstra(vector<vector< pair<int, int>>>&grafo,int source, int evita) {

    vector<int> distancias(grafo.size(), INT_MAX);

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0 , source });

    distancias[source] = 0;

    while (!pq.empty()) {

        int vertice_saida = pq.top().second;

        pq.pop();

        for (auto& p : grafo[vertice_saida]) {

            int vertice_atual = p.first; int weight = p.second;


            if (distancias[vertice_atual] > distancias[vertice_saida] + weight && vertice_atual!=evita) {


                distancias[vertice_atual] = distancias[vertice_saida] + weight;


                pq.push({ distancias[vertice_atual] , vertice_atual });

            }
        }
    }
    return distancias;
}

int main() {
    int vertices, arestas;
    while (cin >> vertices >> arestas) {
    vector<vector< pair<int, int>>> grafo(vertices);
    int v1, v2;
    for (int i = 0; i < arestas; i++) {
        cin >> v1 >> v2;
        grafo[v1-1].push_back({ v2-1 , 1 });
        grafo[v2-1].push_back({ v1-1 , 1 });
    }
    int origem, destino, evita;
    cin >> origem >> destino >> evita;
    vi distancias = dijkstra(grafo, origem - 1, evita - 1);
    cout << distancias[destino-1] << endl;
   }
    return 0;
}


