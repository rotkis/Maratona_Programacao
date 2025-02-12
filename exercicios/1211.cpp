#include <bits/stdc++.h>
//1076

using namespace std;

int main(){
    int n_telefone;
    while(cin >> n_telefone){

        cin.ignore();
        string telefone;
        vector<string> telefones;

        for(int  i = 0; i < n_telefone; i++){
            getline(cin,telefone);
            telefones.push_back(telefone);
        }

        int digitos_salvos = 0;

        sort(telefones.begin(),telefones.end());

        for(int i = 0; i < telefones.size() - 1; i++){
            for(int j = 0; j < telefone.size(); j++){
                if(telefones[i][j] == telefones[i + 1][j]){
                    digitos_salvos++;
                }else{
                    break;
                }
            }
        }

        cout << digitos_salvos << endl;



}
}
