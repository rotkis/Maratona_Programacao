#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    char mapa[1002][1002];
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mapa[i][j];
        }
    }
    
    int coast = 0;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (mapa[i][j] == '#') {
                if (i == 0 || i == M - 1 || j == 0 || j == N - 1 ||
                    mapa[i - 1][j] == '.' || mapa[i + 1][j] == '.' || mapa[i][j - 1] == '.' || mapa[i][j + 1] == '.') {
                    coast++;
                }
            }
        }
    }
    
    cout << coast << endl;
    
    return 0;
}

