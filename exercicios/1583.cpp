#include <bits/stdc++.h>
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
#include <functional>


#define INF INT_MAX
#define MAIOR 1024
using namespace std;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<int> si;
typedef queue<int> qi;
typedef vector<vi> gra;
typedef vector<vc> matriz;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;
gra grafo(MAIOR);
vi visitados(MAIOR, 0);
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(matriz &M, int i, int j) {
    M[i][j] = 'T';

    for (int a = 0; a < 4; a++) {
        int novoi = i + dx[a];
        int novoj = j + dy[a];

        if (novoi >= 0 && novoi < M.size() && novoj >= 0 && novoj < M[0].size() && M[novoi][novoj] == 'A') {
            dfs(M, novoi, novoj);
        }
    }
}

int main() {
    int linha, coluna;

    while (cin >> linha >> coluna) {
        if(linha == 0 && coluna== linha){
            break;
        }

        matriz M(linha, vc(coluna));
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                cin >> M[i][j];
            }
        }

        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                if (M[i][j] == 'T') {
                    dfs(M, i, j);
                }
            }
        }

        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                cout << M[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

