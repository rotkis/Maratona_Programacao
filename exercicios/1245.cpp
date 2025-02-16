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
#define MAIOR 101
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
// and = &&
// or = ||
struct bota {
    char pe;
    string num;
};
// Função de comparação para sort
bool comparaBota(const bota& a, const bota& b) {
    return a.num < b.num;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int vezes;
    while (cin >> vezes) {
        vector<bota> botas(vezes);
        int cont = 0;

        for (int i = 0; i < vezes; i++) {
            cin >> botas[i].num >> botas[i].pe;
        }
        // Ordena o vetor com base nos números das botas
        sort(botas.begin(), botas.end(), comparaBota);
        
        for (int z = 0; z < botas.size(); z++) {
            for (int i = z + 1; i < botas.size(); i++)
            {

                if (botas[z].num == botas[i].num && botas[z].pe != botas[i].pe) {
                    cont++;
                    botas[z].num = 2;
                    botas[i].num = 1;
                    break;
                }
                
            }
        }
        cout << cont << endl;
        botas.clear();
    }
    return 0;
}
