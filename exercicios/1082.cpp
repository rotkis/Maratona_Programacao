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

#define MAXSIZE 35

int* visitados;
char adj[MAXSIZE][MAXSIZE];
int vertices[MAXSIZE];
int tam;
vector<vector<int>> grafo;

void dfs(int rotulo);

int main() {
    int casos, j;
    int caso = 0;
    cin >> casos;
    for (int e = 0; e < casos; e++) {

        int vertice, arestas;

        cin >> vertice >> arestas;

        grafo.resize(vertice);

        visitados = new int[vertice];

        fill_n(visitados, vertice, 0);

        for (int i = 0; i < arestas; i++) {
            char v1, v2;
            cin >> v1 >> v2;
            int i1 = v1 - 'a';
            int i2 = v2 - 'a';
            grafo[i1].push_back(i2);
            grafo[i2].push_back(i1);
        }
        printf("Case #%d:\n", ++caso);
        int ans = 0;
        for (int i = 0; i < vertice; ++i) {
            if (!visitados[i]) {
                ++ans, dfs(i);

                // Sorting vertices in ascending order based on ASCII values
                sort(vertices, vertices + tam);

                for (j = 0; j < tam; ++j)
                    printf("%c,", vertices[j] + 'a');

                printf("\n");
            }

            tam = 0;
        }

        printf("%d connected components\n", ans);
        printf("\n");

        delete[] visitados;
        grafo.clear();
    }
}

void dfs(int rotulo) {
    visitados[rotulo] = 1;
    vertices[tam++] = rotulo;

    for (int i = 0; i < grafo[rotulo].size(); i++) {
        if (visitados[grafo[rotulo][i]] == 0) {
            dfs(grafo[rotulo][i]);
        }
    }
}
