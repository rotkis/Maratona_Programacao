#include <bits/stdc++.h>
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
#define INF INT_MAX
#define MAIOR 10001
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef vector<vi> Graph;
typedef map<string, int > msi;
typedef map<string, vector<string>> msvs;

int main(){
    int dados;
    vi retangulo;
    for(int i = 0; i < 4; i++){
        cin >> dados;
        retangulo.push_back(dados);
    }
    sort(retangulo.begin(), retangulo.end());
    if(retangulo[0] * retangulo[3] == retangulo[1] * retangulo[2]){
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }
    return 0;
}

