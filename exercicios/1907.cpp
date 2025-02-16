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
#include <sys/resource.h>

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


void dfs(int linha, int coluna, matriz& M) {
    M[linha][coluna] = 'o';
    for (int a = 0; a < 4; a++) {
        int new_i = linha + dx[a];
        int new_j = coluna + dy[a];
        if (new_i >= 0 && new_i < M.size() && new_j >= 0 && new_j < M[0].size() && M[new_i][new_j] == '.') {
            dfs(new_i, new_j, M);
        }
    }
}

void setstack(void)
{
    const rlim_t kStackSize = 64L * 1024L * 1024L;   // min stack size = 64 Mb
    struct rlimit rl;
    int result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0 && rl.rlim_cur < kStackSize)
    {
        rl.rlim_cur = kStackSize;
        result = setrlimit(RLIMIT_STACK, &rl);
        if (result != 0)
            fprintf(stderr, "setrlimit returned result = %d\n", result);
    }
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    setstack();

    int linha, coluna;
    cin >> linha >> coluna;
    matriz M(linha, vc(coluna, 'o'));

    int cont = 0;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            cin >> M[i][j];
        }

    }
    
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (M[i][j] == '.') {
                dfs(i, j, M);
                cont++;
             }
        }

    }
    cout << cont << endl;

    


    return 0;
}

