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
    int casos;
    cin >> casos;

    for (int i = 0; i < casos; i++) {
        int qtd_vagoes;
        cin >> qtd_vagoes;

        vector<int> vagoes(qtd_vagoes); // Inicialize o vetor com o tamanho adequado

        for (int j = 0; j < qtd_vagoes; j++) {
            cin >> vagoes[j];
        }

        int swaps = 0; // Contador de trocas

        for (int j = 0; j < qtd_vagoes; j++) {
            for (int k = j + 1; k < qtd_vagoes; k++) {
                if (vagoes[j] > vagoes[k]) {
                    swap(vagoes[j], vagoes[k]);
                    swaps++; // Incrementa o contador de trocas
                }
            }
        }

        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }
}


