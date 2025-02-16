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
#define MAIOR 10001
using namespace std;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> Graph;

Graph grafo(MAIOR);
int inverter(int valor) {
	int inv = 0;
	while (valor != 0) {
		inv = inv * 10 + valor %10;
		valor /= 10;
		
	}
	return inv;
}
void criarGrafo() {
	for (int x = 1; x < MAIOR; x++) {
		grafo[x].push_back(x + 1);
		if (inverter(x) < MAIOR) {
			grafo[x].push_back(inverter(x));
		}
	}
}
int bfs( int origem, int destino) {
	queue<int>q;
	vi dist(MAIOR, INF);
	vi visitados(MAIOR, 0);
	dist[origem] = 0;
	visitados[origem] = 0;
	q.push(origem);
	while (!q.empty()) {
		int atual = q.front();
		int distatual = dist[atual];
		q.pop();
		if (atual == destino)break;
		for (int& vizinho : grafo[atual]) {
			if (visitados[vizinho] == 0 && distatual + 1 < dist[vizinho]) {
				visitados[vizinho] = 1;
				dist[vizinho] = distatual + 1;
				q.push(vizinho);
			}
		}
	}
	if (dist[destino] == INF) return -1;
	return dist[destino];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	criarGrafo();

	int testes;
	cin >> testes;
	for (int i = 0; i < testes; i++) {
		int origem, destino;
		cin >> origem >> destino;
		cout << bfs(origem, destino) << endl;
	}
}
