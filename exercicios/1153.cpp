#include <iostream>

// Função para calcular o fatorial
int calcularFatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * calcularFatorial(n - 1);
    }
}

int main() {
    // Entrada de dados
    int n;
    std::cin >> n;

    // Verificação se o valor de N está no intervalo especificado
    if (0 < n && n < 13) {
        // Chamada da função e impressão do resultado
        int resultado = calcularFatorial(n);
        std::cout << resultado << std::endl;
    } else {
        std::cout << "O valor de N deve estar no intervalo 0 < N < 13." << std::endl;
    }

    return 0;
}

