#include <cmath>
#include <cstdio>
#include <queue>
#define MAXN 10010
#define gc getchar_unlocked
using namespace std;
long long resposta;
int src[MAXN], weight[MAXN] ,conjuntos;

//função de pegar int melhorada porque sacanf ta bugando(GRRR)
void getint(int &x) {
    register int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}

int find(int x) {
    if (x == src[x]) return x;
    return src[x] = find(src[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    conjuntos--;
    if (weight[x] < weight[y]) src[x] = y;
    if (weight[x] > weight[y])
        src[y] = x;
    else {
        src[x] = y;
        weight[y]++;
    }
}
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
int main(){
    int n;
    getint(n);
    conjuntos = n;
    src[n] = n;
    for (int i = 1; i < n; i++) {
        src[i] = i;
        int pares;
        getint(pares);
        while (pares--) {
            int j, peso;
            getint(j);
            getint(peso);
            q.push(make_pair(peso, make_pair(i, j)));
        }
    }

    while(conjuntos > 1 && !q.empty()){
        pair<int,pair<int,int>> atual = q.top();
        q.pop();

        if(find(atual.second.first) != find(atual.second.second)){
            join(atual.second.first, atual.second.second);
            resposta += atual.first;
        }

    }
    printf("%d %lld\n", conjuntos, resposta);
    return 0;


}
