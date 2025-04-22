#include <iostream>
#include <stdio.h>
#include <climits>
#include <queue>
#include <vector>
#include <cstdio>
#include <map>
#define MAXN 510

using namespace std;



int matriz[MAXN][MAXN];
int percorridos[MAXN][MAXN];

int main(){

    map<char,int> items;

    items['.'] = 0;
    items['H'] = 0;
    items['E'] = 0;
    items['#'] = -1;
    items['1'] = 1;
    items['2'] = 2;
    items['3'] = 3;
    items['4'] = 4;
    items['5'] = 5;
    items['6'] = 6;
    items['7'] = 7;
    items['8'] = 8;
    items['9'] = 9;


    int Hx, Hy , Ex , Ey;
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    for(int i = 1; i <= linhas; i++){
        getchar();
        for(int j = 1; j <= colunas; j++){
            char item;
            scanf("%c", &item);
            if(item == 'H'){
                Hx = i;
                Hy = j;
            }

            if(item == 'E'){
                Ex = i;
                Ey = j;
            }

            matriz[i][j] = items[item];

        }
    }

    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>> q;

    q.push(make_pair(0,make_pair(Hx,Hy)));

    while (!q.empty()) {
        pair<int,pair<int,int>> atual = q.top();
        q.pop();
        int percorrido = atual.first, cord1 = atual.second.first,
            cord2 = atual.second.second;
        if (cord1 == Ex && cord2 == Ey) {
            printf("%d\n", percorrido);
            return 0;
        }
        if (percorridos[cord1][cord2]) continue;
        percorridos[cord1][cord2] = 1;
        if (cord1 + 1 <= linhas && matriz[cord1 + 1][cord2] != -1)
            q.push(make_pair(percorrido + matriz[cord1 + 1][cord2],
                             make_pair(cord1 + 1, cord2)));
        if (cord1 - 1 > 0 && matriz[cord1 - 1][cord2] != -1)
            q.push(make_pair(percorrido + matriz[cord1 - 1][cord2],
                             make_pair(cord1 - 1, cord2)));
        if (cord2 + 1 <= colunas && matriz[cord1][cord2 + 1] != -1)
            q.push(make_pair(percorrido + matriz[cord1][cord2 + 1],
                             make_pair(cord1, cord2 + 1)));
        if (cord2 - 1 > 0 && matriz[cord1][cord2 - 1] != -1)
            q.push(make_pair(percorrido + matriz[cord1][cord2 - 1],
                             make_pair(cord1, cord2 - 1)));
    }
    printf("ARTSKJID\n");
    return 0;
}
