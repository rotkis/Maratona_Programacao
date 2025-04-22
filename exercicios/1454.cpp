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
#define MAIOR 10000
#define MAx 110
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<int> si;
typedef queue<int> qi;
typedef vector<vector<pii>> gra;
typedef vector<vi> graph;
typedef vector<vc> matriz;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int instacia = 1;
    int cidade, caminho, pares;
    int dist[MAx][MAx];
   while (cin >> cidade >> caminho){
       if (cidade == 0 && cidade == caminho) break;
       cout << "Instancia " << instacia++ << endl;
       
        for (int i = 0; i <= cidade; i++) {
            for (int j = 0; j <= cidade; j++) {
                dist[i][j] = MAIOR;
            }
        }

        for (int j = 0; j < caminho; j++) {
            int rotA, rotB, peso;
            cin >> rotA >> rotB >> peso;
            dist[rotA][rotB] = dist[rotB][rotA] = min(peso, dist[rotA][rotB]);
        }
        for (int k = 1; k <= cidade; k++)
        {
            for (int i = 1; i <= cidade; i++)
            {
                for (int j = 1; j <= cidade; j++)
                {

                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));

                }
            }
        }
        for (int i = 0; i <= cidade; i++) {
            dist[i][i] = 0;
        }
        cin >> pares;
        for (int i = 0; i < pares; i++) {
            int source, destiny;
            cin >> source >> destiny;

            cout << dist[source][destiny]<< endl;

        }
        cout << endl;

       
    }


    return 0;
}
