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
#define MAIOR 100001
using namespace std;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> Graph;

Graph grafo(MAIOR);

void criarGrafo() {
	for (int x = 1; x < MAIOR; x++) {
		if (x * 3 < MAIOR) {
			grafo[x].push_back(x*3);
		}
		if (x * 2 < MAIOR) {
			grafo[x].push_back(x * 2);
		}
		if (x +1 < MAIOR) {
			grafo[x].push_back(x +1);
		}
		if (x %2 == 0) {
			grafo[x].push_back(x /2);
		}
		grafo[x].push_back(x - 1);
	}
}
int bfs(si &proibido,int origem, int destino) {
	queue<int>q;
	vi dist(MAIOR	, INF)	;
	vi visitados(MAIOR, 0);
	dist[origem] = 0;
	visitados[origem] = 0;
	q.push(origem);
	while (!q.empty()) {
		int atual= q.front();
		int distatual = dist[atual];
		q.pop();
		if (atual == destino)break;
		for (int& vizinho : grafo[atual]) {
			if (visitados[vizinho]== 0 && distatual +1 < dist[vizinho] && proibido.count(vizinho)==0){
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
	int origem, destino, pribido;
	while (cin >> origem >> destino >> pribido) {
		if (origem == destino&&destino== pribido &&pribido== 0)break;
		si erro;
		for (int i = 0; i < pribido; i++) {
			int proibido;
			cin >> proibido;
			erro.insert(proibido);
		}
		cout << bfs(erro, origem, destino) << endl;
		
	}
}
