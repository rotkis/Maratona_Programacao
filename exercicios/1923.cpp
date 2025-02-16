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
typedef vector<string> vs;
typedef set<int> si;
typedef vector<vi> Graph;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;

Graph grafo(MAIOR);


msi bfs(msvs &grafo, string origem, int destino) {
	queue<string>q;
	int cont = 0;
	int camada = 0;
	msi dist;
	msi visitados;
	for (auto l : grafo) {
		visitados[l.first] = 0;
		dist[l.first] = INF;
	}
	dist[origem] = 0;
	visitados[origem] = 0;
	q.push(origem);
	while (!q.empty()) {
		string atual = q.front();
		int distatual = dist[atual];
		q.pop();
		
		for (string& vizinho : grafo[atual]) {
			if (visitados[vizinho] == 0 && distatual + 1 < dist[vizinho]) {
				visitados[vizinho] = 1;
				dist[vizinho] = distatual + 1;
				q.push(vizinho);
			}
		}
	}
	return  dist;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	int relacoes, grau;
	cin >> relacoes >> grau;
	map<string, vector<string>> grafo;
	for (int i = 0; i < relacoes; i++) {
		string origem, destino;
		cin >> origem >> destino;
		grafo[origem].push_back(destino);
		grafo[destino].push_back(origem);
	}
	msi resp = bfs(grafo, "Rerisson", grau);
	set<string>resps;
	for (auto i : resp) {
		if (i.second <= grau&&i.second!=0) {
			resps.insert(i.first);
		}
	}
	cout << resps.size() << endl;
	for (auto i : resps) {
		cout << i << endl;
	}
	
}
