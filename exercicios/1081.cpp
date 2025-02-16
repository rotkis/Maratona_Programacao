#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAXSIZE 30

#define true 1
#define false 0



int v;
int flag;
char esp[MAXSIZE];
int vis[MAXSIZE];
int adj[MAXSIZE][MAXSIZE];

void dfs(int);

int main() {
    int u, w;
    int n, e, i, caso = 0;

    std::cin >> n;

    while (n--) {
        std::cin >> v >> e;

        // Use std::fill for array initialization
        std::fill(vis, vis + MAXSIZE, 0);
        std::fill(&adj[0][0], &adj[MAXSIZE - 1][MAXSIZE], 0);

        for (i = 0; i < e; ++i)
            std::cin >> u >> w, adj[u][w] = 1;

        std::cout << "Caso " << ++caso << ":\n";
        for (i = 0; i < v; ++i) {
            esp[0] = '\0'; // Initialize esp as an empty string
            flag = 0;
            if (!vis[i])
                dfs(i);

            if (flag)
                std::cout << '\n';
        }
    }

    return 0;
}

void dfs(int u) {
    int i;
    vis[u] = 1;
    strcat(esp, "  ");

    for (i = 0; i < v; ++i) {
        if (adj[u][i]) {
            flag = 1;
            if (!vis[i]) {
                std::cout << esp << u << '-' << i << " pathR(G," << i << ")\n";
                dfs(i);
                esp[strlen(esp) - 2] = '\0'; // Remove the last two characters from esp
            } else {
                std::cout << esp << u << '-' << i << '\n';
            }
        }
    }
}

