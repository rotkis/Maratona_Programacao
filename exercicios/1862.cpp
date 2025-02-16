#include <bits/stdc++.h>

using namespace std;

vector<int> V;
vector<vector<int>> G;
vector<int> grafos;

void bfs(int node, int house);

int main() {
    set<string>M;
    int tamanho;
    cin >> tamanho;

    G.resize(tamanho);

    V.resize(tamanho, 0);

    grafos.clear();

    for (int i = 0; i < tamanho; i++) {
        string letras;

        cin >> letras;

        M.insert(letras);

        for (int j = 0; j < tamanho; j++) {

            if (letras[j] == 'S') {

                G[i].push_back(j);

            }
        }

    }

    int num_houses = 0;

    for (int i = 0; i < tamanho; i++) {
        if (V[i] == 0) {
            num_houses++;
            bfs(i, num_houses);

        }
    }
    ;

    if (num_houses != M.size()) {
        cout << -1 << endl;
    }
    else {
        if (num_houses == 1) {

            cout << 1 << endl;
            cout << tamanho << endl;

        }

        else {

            sort(grafos.rbegin(), grafos.rend());
            cout << num_houses << endl;
            for (int j = 0; j < grafos.size(); j++) {
                if (j == grafos.size() - 1) {
                    cout << grafos[j];
                }
                else {
                    cout << grafos[j] << " ";
                }

            }
            cout << endl;
        }
    }

    return 0;
}

void bfs(int node, int house) {
    stack<int> Q;

    V[node] = 1;

    Q.push(node);

    grafos.push_back(0); 

    while (!Q.empty()) {

        int t = Q.top();

        Q.pop();

        grafos[house - 1]++;

        for (int i = 0; i < G[t].size(); i++) {

            if (V[G[t][i]] == 0) {

                V[G[t][i]] = 1;

                Q.push(G[t][i]);
            }
        }
    }
}
