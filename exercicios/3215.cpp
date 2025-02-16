#include <bits/stdc++.h>
using namespace std;

vector<int> visitados;
vector<vector<int>> grafo;
int soma=0;

vector<int> teste;
vector<int> valores;
void dfs(int rotulo);

int main()
{
    int valor;
    int vertices , arestas;
    cin >> vertices >> arestas;


    for(int i = 0; i < vertices; i++){
        cin >> valor;
        valores.push_back(valor);
    }

    grafo.resize(vertices);
    visitados.resize(vertices,0);

    int v1 , v2;

    for(int i = 0; i < arestas; i++){
        cin >> v1 >> v2;

        grafo[v1].push_back(v2);
        grafo[v2].push_back(v1);
    }

    int check = 1;

    for(int i = 0; i < grafo.size(); i++){
        if(visitados[i] == 0){
            soma=0;
            dfs(i);
            if (soma!=0){
                break;
            }
        }
    }

    if(soma==0){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;

}

void dfs(int rotulo){
    soma+=valores[rotulo];
    visitados[rotulo] = 1;

    teste.push_back(rotulo);

    for(int i = 0; i < grafo[rotulo].size();i++){
        if(visitados[grafo[rotulo][i]] == 0){

            dfs(grafo[rotulo][i]);

        }
    }


}
