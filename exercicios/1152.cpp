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

// Define uma estrutura para representar uma aresta do grafo
struct Edge {
    int src, dest; double weight;
};

// Define uma classe para representar um grafo
class Graph {
public:
    int V; // Número de vértices
    vector<Edge> edges; // Vetor de arestas do grafo
    vector<vector<int>> adj; // Matriz de adjacência

    Graph(int v) : V(v), adj(v, vector<int>()) {}


    // Função para adicionar uma aresta ao grafo
    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
        adj[src].push_back(dest); // Adiciona a aresta à matriz de adjacência
    }

    // Função auxiliar para encontrar o conjunto (representante) de um vértice em uma floresta de conjuntos disjuntos
    int findSet(vector<int>& parent, int v) {
        if (parent[v] == -1)
            return v;
        return findSet(parent, parent[v]);
    }

    // Função auxiliar para unir dois conjuntos em uma floresta de conjuntos disjuntos
    void unionSets(vector<int>& parent, int x, int y) {
        int rootX = findSet(parent, x);
        int rootY = findSet(parent, y);
        parent[rootX] = rootY;
    }

    // Função para encontrar a árvore geradora mínima usando o algoritmo de Kruskal
    double KruskalMST() {
        vector<int> parent(V, -1); // Vetor para rastrear os pais dos vértices na floresta de conjuntos disjuntos
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
            });

        double soma = 0;
        int numArestasSelecionadas = 0;

        for (Edge edge : edges) {
            int src = edge.src;
            int dest = edge.dest;
            double weight = edge.weight;

            int setSrc = findSet(parent, src);
            int setDest = findSet(parent, dest);

            if (setSrc != setDest) {
                // Aresta não cria ciclo
                soma += weight;
                unionSets(parent, setSrc, setDest);
                numArestasSelecionadas++;
            }

            // Parar quando todas as arestas necessárias foram selecionadas (V-1 arestas)
            if (numArestasSelecionadas == V - 1)
                break;
        }

        if (numArestasSelecionadas != V - 1)
            return -1; // Grafo não é conexo

        return soma;
    }

    // Função para encontrar a árvore geradora mínima usando o algoritmo de Prim
    int PrimMST(int inicio) {
        vector<int> parent(V, -1); // Vetor para rastrear os pais dos vértices na MST
        vector<int> key(V, INT_MAX); // Vetor para rastrear as chaves (pesos mínimos)
        vector<bool> inMST(V, false); // Vetor para rastrear os vértices incluídos na MST

        // Usando um par (chave, vértice) para manter os vértices disponíveis
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Inicializa o primeiro vértice como raiz
        int src = inicio;
        key[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (Edge edge : edges) {
                if (edge.src == u) {
                    int v = edge.dest;
                    int weight = edge.weight;

                    // Se v não estiver na MST e a aresta u-v tiver um peso menor do que a chave atual de v
                    if (!inMST[v] && weight < key[v]) {
                        parent[v] = u;
                        key[v] = weight;
                        pq.push(make_pair(key[v], v));
                    }
                }
            }
        }

        // Imprime a árvore geradora mínima

        cout << "Arestas da Árvore Geradora Mínima:\n";
        for (int i = 0; i < V; i++) {
            cout << "Aresta: " << parent[i] + 1 << " - " << i + 1 << " | Peso: " << key[i] << endl;
        }



        int soma = 0;
        for (int i = 0; i < parent.size(); i++) {
            soma += key[i];
        }
        return soma;

    }

    // Função para encontrar o caminho mais curto de um vértice de origem para todos os outros usando o algoritmo de Dijkstra
    vector<double> Dijkstra(int src) {
        vector<double> dist(V, INT_MAX); // Vetor para rastrear as distâncias mínimas
        dist[src] = 0;

        // Usando um par (distância, vértice) para manter os vértices disponíveis
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (Edge edge : edges) {
                if (edge.src == u) {
                    int v = edge.dest;
                    double weight = edge.weight;

                    // Relaxamento da aresta
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }
        return dist;
    }

    // Função para realizar uma busca em largura (BFS) a partir de um vértice de origem
    vector<int> BFS(int src) {
        vector<int> distance(V, -1); // Vetor para rastrear as distâncias
        queue<int> q;

        distance[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (Edge edge : edges) {
                if (edge.src == u) {
                    int v = edge.dest;

                    if (distance[v] == -1) {
                        distance[v] = distance[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        return distance;
    }

    // Função para realizar uma busca em profundidade (DFS) a partir de um vértice de origem
    vector<bool> DFS(int src) {
        vector<bool> visited(V, false); // Vetor para rastrear os vértices visitados
        stack<int> stk;

        stk.push(src);

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();

            if (!visited[u]) {
                visited[u] = true;
                //cout << u << " "; // Faça o que desejar com o vértice visitado

                // Empilhe todos os vizinhos não visitados
                for (Edge edge : edges) {
                    if (edge.src == u) {
                        int v = edge.dest;
                        if (!visited[v]) {
                            stk.push(v);
                        }
                    }
                }
            }
        }
        return visited;
    }
    bool hasCycleDFS(int v, vector<bool>& visited, vector<bool>& stack) {
        visited[v] = true;
        stack[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (hasCycleDFS(neighbor, visited, stack)) {
                    return true;
                }
            }
            else if (stack[neighbor]) {
                return true;
            }
        }

        stack[v] = false;
        return false;
    }

    // Função para verificar se o grafo é cíclico
    bool hasCycle() {
        vector<bool> visited(V, false);
        vector<bool> stack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (hasCycleDFS(i, visited, stack)) {
                    return true;
                }
            }
        }

        return false;
    }
    // Função para realizar uma busca em profundidade contando o número de vértices alcançados
    int DFS_CONT(int src) {
        vector<bool> visited(V, false);
        stack<int> stk;

        stk.push(src);
        visited[src] = true;
        int count = 1; // Inicializa o contador com 1 para incluir o vértice de origem

        while (!stk.empty()) {
            int u = stk.top();
            stk.pop();

            for (Edge edge : edges) {
                if (edge.src == u) {
                    int v = edge.dest;
                    if (!visited[v]) {
                        visited[v] = true;
                        stk.push(v);
                        count++; // Incrementa o contador ao visitar um novo vértice
                    }
                }
            }
        }

        return count;
    }

    bool hasCycleTarjan() {
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> stackMember(V, false);
        stack<int> stk;
        int startVertex = 0; // Vértice de partida (pode ser qualquer um)

        std::function<bool(int)> hasCycle = [&](int v) {
            static int time = 0;

            disc[v] = low[v] = ++time;
            stk.push(v);
            stackMember[v] = true;

            for (int neighbor : adj[v]) {
                if (disc[neighbor] == -1) {
                    if (hasCycle(neighbor))
                        return true;

                    low[v] = min(low[v], low[neighbor]);
                }
                else if (stackMember[neighbor]) {
                    low[v] = min(low[v], disc[neighbor]);
                }
            }

            if (low[v] == disc[v]) {
                int poppedVertex;
                do {
                    poppedVertex = stk.top();
                    stk.pop();
                    stackMember[poppedVertex] = false;
                } while (poppedVertex != v);
            }

            return false;
        };

        // Verifique se há ciclo a partir de cada vértice
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                startVertex = i;
                if (hasCycle(i)) {
                    return false; // Se houver ciclo a partir de qualquer vértice, não é possível sair e voltar de qualquer lugar
                }
            }
        }

        // Verifique se é possível alcançar todos os vértices a partir do vértice de partida
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int neighbor : adj[u]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Verifique se todos os vértices foram alcançados a partir do vértice de partida
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return false; // Não é possível alcançar todos os vértices a partir do vértice de partida
            }
        }

        return true; // É possível sair de qualquer ponto e voltar a qualquer lugar
    }


};
double dist(int x, int y, int x1, int y1) {
    return sqrt(pow((x - x1), 2) + pow((y - y1), 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int jun, estr;
    while (cin >> jun >> estr) {
        if (jun == 0 && jun == estr) {
            break;
        }
    Graph grafo(jun);
    int soma = 0;
    for (int i = 0; i < estr; i++)
    {
        int salA, salB ,liga;
        cin >> salA >> salB >> liga;
        grafo.addEdge(salA , salB, liga);
        soma += liga;
    }
    int valor = grafo.KruskalMST();
    int res = soma - valor;
    cout << res << endl;
    
    }
    return 0;
}

