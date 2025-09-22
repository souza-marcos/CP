#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, m; cin >> n >> m;
    vector<int> freq(m+1);

    vector<vector<int>> arr(n);
    for(auto& row: arr) {
        int s; cin >> s;
        row.resize(s);
        for(int & el : row) cin >> el, freq[el] ++;
    }

    for(int i = 1; i < sz(freq); i ++){
        if(freq[i] == 0){
            cout << "NO\n";
            return;
        }
    }

    int id = -1;
    for(int i = 0; i < n; i ++){

        bool ok = true;
        for(int el : arr[i]){
            if(freq[el] == 1) ok = false;
            freq[el] --;
        }

        for(int el : arr[i]){
            freq[el] ++;
        }


        if(ok == true and id != -1){
            cout << "YES\n";
            return;
        }

        if(ok == true) id = i;
    }
    if(id == -1) {
        cout << "NO\n";
        return;
    }

    for(int el : arr[id]) freq[el]--;
    for(int i = 0; i < n; i ++){
        if(i == id) continue;

        bool ok = true;
        for(int el : arr[i]){
            if(freq[el] == 1) ok = false;
            freq[el] --;
        }


        for(int el : arr[i]){
            freq[el] ++;
        }

        if(ok == true){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main(){ _

    // Todo mundo, tenta remover um (Se tiver dois que da, acabou. Se não tenta remover mais um do anterior).
    int t; cin >> t;
    while(t--) solve();
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