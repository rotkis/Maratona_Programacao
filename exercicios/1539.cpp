#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#define MAXN 110
#define LIMIT 9999999.0
using namespace std;

vector<vector<double>> dists(MAXN, vector<double>(MAXN, LIMIT));
vector<double> coordenadasx(MAXN), coordenadasy(MAXN), raios(MAXN);

int main() {
    int n, m;
    while (cin >> n && n != 0) {
        for (int i = 1; i <= n; i++) {
            cin >> coordenadasx[i] >> coordenadasy[i] >> raios[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                double dist = sqrt(pow(coordenadasx[i] - coordenadasx[j], 2) +
                                   pow(coordenadasy[i] - coordenadasy[j], 2));

                if (dist <= raios[i]) {
                    dists[i][j] = dist;
                } else {
                    dists[i][j] = LIMIT;
                }
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }

        cin >> m;

        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            if (dists[a][b] == LIMIT)
                cout << "-1\n";
            else
                printf("%.0lf\n", floor(dists[a][b]));
        }
    }

    return 0;
}

