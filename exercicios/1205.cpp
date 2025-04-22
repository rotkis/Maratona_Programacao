#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#define MAXN 1010
using namespace std;

vector<int> grafo[MAXN];
int soldados[MAXN], alcansados[MAXN], pontos, caminhos, balas;
double probabilidade;

int main() {
	while (scanf("%d %d %d %lf", &pontos, &caminhos, &balas, &probabilidade) != EOF) {
		int consegue = 0;
		for (int i = 1; i <= pontos; i++) {
			grafo[i].clear();
			soldados[i] = 0;
			alcansados[i] = 0;
		}

		for (int i = 0; i < caminhos; i++) {
			int v1, v2;
			scanf("%d %d",&v1, &v2);
			grafo[v1].push_back(v2);
			grafo[v2].push_back(v1);
		}

		int n_soldados;
		scanf("%d", &n_soldados);
		while (n_soldados--) {
			int lugar;
			scanf("%d", &lugar);
			soldados[lugar]++;
		}

		priority_queue<pair<int, int>> q;

		int inicio, fin;

		scanf("%d %d", &inicio, &fin);
		q.push(make_pair(balas - soldados[inicio], inicio));
		while (!q.empty()) {
			pair<int, int> atual = q.top();
			q.pop();
			int n_balas = atual.first;
			int pos = atual.second;
			if (n_balas < 0) {
				continue;
			}
			if (pos == fin) {
				consegue = 1;
				printf("%.3lf\n", pow(probabilidade, balas - n_balas));
				break;
			}

			if (alcansados[pos]) {
				continue;
			}

			alcansados[pos] = 1;

			for (int i = 0; i < grafo[pos].size(); i++) {
				int next = grafo[pos][i];
				q.push(make_pair(n_balas - soldados[next], next));
			}

		}

		if (!consegue) {
			printf("0.000\n");
		}

	}

	return 0;
}
