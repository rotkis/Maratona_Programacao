#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// and = &&
// or ||
int main() {
    int linhas, colunas;
    int tabuleiro[100][100];

    while (cin >> linhas >> colunas) {
        // Ler a entrada e preencher o tabuleiro
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                int valor;
                cin >> valor;
                if (valor == 1) {
                    tabuleiro[i][j] = 9; // Se houver um pão de queijo, marque como 9
                }
                else {
                    tabuleiro[i][j] = 0; // Caso contrário, inicialize como 0
                }
            }
        }

        // Calcular os números nas células do tabuleiro (horizontal e vertical)
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (tabuleiro[i][j] == 9) {
                    continue; // Se já é um pão de queijo, não precisa calcular.
                }

                int n = 0;

                // Verificar as células adjacentes na horizontal e vertical
                if (i > 0 && tabuleiro[i - 1][j] == 9) {
                    n++;
                }
                if (i < linhas - 1 && tabuleiro[i + 1][j] == 9) {
                    n++;
                }
                if (j > 0 && tabuleiro[i][j - 1] == 9) {
                    n++;
                }
                if (j < colunas - 1 && tabuleiro[i][j + 1] == 9) {
                    n++;
                }

                tabuleiro[i][j] = n;
            }
        }

        // Imprimir o tabuleiro final
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << tabuleiro[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}


