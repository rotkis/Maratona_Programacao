#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aluno {
    int nota;
    int ordem;

    Aluno(int _nota, int _ordem) : nota(_nota), ordem(_ordem) {}

    bool operator<(const Aluno& outro) const {
        return nota > outro.nota;
    }
};

int main() {
    int casos;
    cin >> casos;

    for (int caso = 0; caso < casos; caso++) {
        int n;
        cin >> n;

        vector<Aluno> alunos;

        for (int i = 0; i < n; i++) {
            int nota;
            cin >> nota;
            alunos.push_back(Aluno(nota, i));
        }

        sort(alunos.begin(), alunos.end());

        int naoPrecisaramTrocar = 0;
        for (int i = 0; i < n; i++) {
            if (alunos[i].ordem == i) {
                naoPrecisaramTrocar++;
            }
        }

        cout << naoPrecisaramTrocar << endl;
    }

    return 0;
}
