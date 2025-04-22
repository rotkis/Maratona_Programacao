#include <iostream>
#include <stdio.h>
#include <climits>
#include <queue>
#include <vector>
#include <map>

using namespace std;

vector<vector<pair<int, int>>> grafo;
vector<int> distancias;

void dijkstra(int source, int dest);

void dijkstra(int source, int dest) {

    distancias.resize(grafo.size(), INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, source });

    distancias[source] = 0;

    while (!pq.empty()) {

        int vertice_saida = pq.top().second;
        int distancia_atual = pq.top().first;



        pq.pop(); // Remova o vértice da fila após processá-lo

        if (vertice_saida == dest) {
            break;
        }

        for (auto& p : grafo[vertice_saida]) {

            int vertice_atual = p.first;
            int weight = p.second;

            

            if (distancias[vertice_atual] > distancia_atual + weight) {

                distancias[vertice_atual] = distancia_atual + weight;

                pq.push({ distancias[vertice_atual], vertice_atual });

              
            }
        }
    }

}

int main() {

    map<string, int> lugares;

    int X, N, V;

    while (cin >> X >> N >> V) {
        if (X == 0 && N == 0 && V == 0) {
            break;
        }

        if (X > 30) {
            X = 50;
        }
        else {
            X = 30;
        }

        int place = 0;
        grafo.resize(V);

        string p1, p2;
        int time;

        for (int i = 0; i < N; i++) {
            cin >> p1 >> p2 >> time;
            if (lugares.find(p1) == lugares.end()) {
                lugares[p1] = place;
                place++;
            }
            if (lugares.find(p2) == lugares.end()) {
                lugares[p2] = place;
                place++;
            }

            if (p1 == "alto") {
                grafo[lugares[p1]].push_back({ lugares[p2], INT_MAX });
            }
            else {
                grafo[lugares[p1]].push_back({ lugares[p2], time });
                grafo[lugares[p2]].push_back({ lugares[p1], time });

            }
        }

        dijkstra(lugares["varzea"], lugares["alto"]);

        int tempo = distancias[lugares["alto"]];

        tempo += X;

        if (tempo < 60) {
            cout << "17:" << tempo << endl;
            cout << "Nao ira se atrasar" << endl;
        }
        else if (tempo == 60) {
            cout << "18:00" << endl;
            cout << "Nao ira se atrasar" << endl;
        }
        else if (tempo > 60) { 
            if (tempo - 60 >= 10) {
                cout << "18:" << tempo - 60 << endl;
            }
            else {
                cout << "18:0" << tempo - 60 << endl;
            }
            cout << "Ira se atrasar" << endl;
        }

        distancias.clear();
        grafo.clear();
        lugares.clear();
    }

    return 0;
}
