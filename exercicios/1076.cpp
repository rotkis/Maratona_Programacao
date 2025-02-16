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
// or = ||
int* visitados;
int cont = 0;
vector<vector<int>> grafo;

void dfs(int rotulo);


int main() {
    int time;
    cin >> time;
    while (time > 0) {
        int rot, vertices, arestas;
        cin >> rot >> vertices >> arestas;

        grafo.resize(vertices);
        visitados = new int[vertices];
        fill_n(visitados, vertices, 0);

        int v1, v2;
        for (int i = 0; i < arestas; i++) {
            cin >> v1 >> v2;

            grafo[v1].push_back(v2);
            grafo[v2].push_back(v1);
        }

        dfs(rot);

        cout << cont << endl;
        cont = 0;
        visitados = new int[0];
        grafo.clear();
        time--;
    }
}

void dfs(int rotulo) {
    visitados[rotulo] = 1;

    for (int i = 0; i < grafo[rotulo].size(); i++) {
        if (visitados[grafo[rotulo][i]] == 0) {
            cont += 2;
            dfs(grafo[rotulo][i]);
        }
    }

}
