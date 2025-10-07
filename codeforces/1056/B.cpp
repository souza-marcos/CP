#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll


void solve(){
    int n, k; cin >> n >> k;
    if(k == n*n -1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string mvs = "RDLU";
    vector<vector<int>> res(n, vector<int>(n, -1));
    int rest = n*n - k;
    if(rest != 0){
        res[0][0] = 0, res[0][1] = 2; 
        rest -= 2;
        for(int i = 1; i < n; i ++){
            if(rest == 0) break;
            res[i][0] = 3;
            rest -= 1;
        }
        for(int i=1; i < n; i ++){
            if(rest == 0) break;
            res[i][1] = 3;
            rest -= 1;
        }

        for(int i = 0; i < n;i ++){
            if(rest == 0) break; 
            for(int j = 2; j < n; j ++){
                if(rest == 0) break;;
                res[i][j] = 2;
                rest -= 1;
            }   
        }    
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++) if(res[i][j] == -1) res[i][j] = 0;
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cout << mvs[res[i][j]];
        }
        cout << endl;
    }
}

int32_t main(){ _ 
    int t; cin >> t;
    while (t--) solve();
} 

/*
 
g++ a.cpp -o main -Wall -fsanitize=address -g 
 
Lembre de mim:
 
em hipótese alguma veja os standings. Veja apenas o Dashboard.
ler a questão
entender o problema
ver os casos de teste
entender os casos de teste
entender o algoritmo naive para resolver o problema
 
(!) sempre tem uma solução (um setter que fez)
(!) Tudo que voce sabe é o suficiente para resolver
 
testar a ideia nos casos de teste e pensar em contra exemplos e casos de borda
 
(!) implementar com calma.
 
-> Se tu está garrado, sem nenhuma ideia, tente fazer chutes.
-> Faça uma BFS.
*/