#include <cmath>
#include <cstdio>
#include <queue>

#define MAXN 10100
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


double posx[MAXN], posy[MAXN];
int main() {

	int testes, pessoas;
	
	scanf("%d", &testes);
	while (testes--) {
		scanf("%d", &pessoas);

		
		
		for(int i = 0; i < pessoas; i++) {
			src[i] = i; //O elemento tem inicialmente ele mesmo como representante/pai
			weight[i] = 0;
			scanf("%lf %lf", &posx[i], &posy[i]);
		}

		priority_queue < pair<double, pair<int, int> >, // fila de prioridade
			vector < pair<double, pair<int, int> > >, //forma como vai armazenar
			greater < pair<double, pair<int, int> > > > q; //parametro de como vai armazenar

		for (int i = 0; i < pessoas; i++) {
			for (int j = i +1; j < pessoas; j++) {
				q.push(make_pair
				(sqrt(((posx[i] - posx[j]) * (posx[i] - posx[j])) + ((posy[i] - posy[j]) * (posy[i] - posy[j]))),
					make_pair(i, j)));
			}
		}

		double teia_minima = 0;


		while (!q.empty()) {
			pair<double, pair<int, int>> atual = q.top();
			q.pop();
			
			if (find(atual.second.first) != find(atual.second.second)) {
				teia_minima += atual.first;
				join(atual.second.first, atual.second.second);
			}

		}
		
		printf("%.2lf\n", teia_minima/100);
	}

	return 0;


}
