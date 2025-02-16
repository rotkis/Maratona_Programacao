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
using namespace std;


int bfs(map<string, vector<string>>& grafo, string origem, string destino) {
	queue<string> q;
	map<string, int > visitados;
	map<string, int > dist;
	for (auto l : grafo) {
		visitados[l.first] = 0;
		dist[l.first] = INF;
	}
	q.push(origem);
	dist[origem] = 0;
	while (!q.empty()){
		string atual = q.front();
		int distAtual = dist[atual];
		q.pop();
		if (atual == destino)break;
		for (string vizinho : grafo[atual]) {
			if (visitados[vizinho]==0&& distAtual+1<dist[vizinho]) {
				visitados[vizinho] = 1;
				dist[vizinho] = distAtual + 1;
				q.push(vizinho);
			}
		}

	}
	return dist[destino];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int pontos, liga;
	cin >> pontos >> liga;
	map<string, vector<string>> grafo;
	for (int i = 0; i < liga; i++) {
		string origem, destino;
		cin >> origem >> destino;
		grafo[origem].push_back(destino);
		grafo[destino].push_back(origem);
	}
	int dista = bfs(grafo,"Entrada","*"), distb= bfs(grafo, "*", "Saida");
	cout << dista + distb << endl;


	return 0;
}

