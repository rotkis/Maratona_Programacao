#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <queue>

#define MAXN 1000100
using namespace std;
int src[MAXN], weight[MAXN];

//duas funções importantes do algoitimo union-find, que são usadas para montar o grafo
int find(int vertice) {
	if (vertice == src[vertice]) {
		return vertice;
	}
	return src[vertice] = find(src[vertice]);

}
	
void join(int vertice1, int vertice2) {
	vertice1 = find(vertice1);
	vertice2 = find(vertice2);

	if (vertice1 == vertice2) {
		return;
	}

	if (weight[vertice1] < weight[vertice2]) {
		src[vertice1] = vertice2;
	}
	if (weight[vertice1] > weight[vertice2]) {
		src[vertice2] = vertice1;
	}
	else {
		weight[vertice2]++;
		src[vertice1] = vertice2;
	}
}


int main() {

	int galerias, entrada, saida, peso;
	
	scanf("%d", &galerias);

	priority_queue < pair<double, pair<int, int> >, 
		vector < pair<double, pair<int, int> > >, 
		greater < pair<double, pair<int, int> > > > q; 

	priority_queue < pair<double, pair<int, int> >, 
		vector < pair<double, pair<int, int> > >, 
		less < pair<double, pair<int, int> > > > q2; 

	for (int i = 0; i < MAXN; i++) {
		src[i] = i; 
		weight[i] = 0;
	}

	for(int i = 0; i < galerias; i++) {
		scanf("%d %d %d", &entrada, &saida, &peso);
		q.push(make_pair(peso, make_pair(entrada, saida)));
		q2.push(make_pair(peso, make_pair(entrada, saida)));
	}

	int valor_minimo = 0;
	int valor_maximo = 0;

	while (!q.empty()) {
		pair<double, pair<int, int>> atual = q.top();
		q.pop();
			
		if (find(atual.second.first) != find(atual.second.second)) {
			valor_minimo += atual.first;
			join(atual.second.first, atual.second.second);
		}

	}

	for (int i = 0; i < MAXN; i++) {
		src[i] = i;
	}

	while (!q2.empty()) {
		pair<double, pair<int, int>> atual = q2.top();
		q2.pop();

		if (find(atual.second.first) != find(atual.second.second)) {
			valor_maximo += atual.first;
			join(atual.second.first, atual.second.second);
		}

	}

	

	printf("%d\n%d\n",valor_maximo, valor_minimo);
	return 0;
}
