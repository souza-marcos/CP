#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> res(n);

    bool ruim = true;
    for(auto el : s) if(el == '1'){
        ruim = false;
    }

    if(ruim){
        cout << "YES\n";
        for(int i = 0; i < n; i ++){
            cout << ((i + 1) % n) + 1 << " ";
        }
        cout << endl;
        return ;
    }


    int cur = 0;
    for(int i = 0; i < n; i ++){
        if(s[i] == '1'){
            res[i] = i;
            int last = cur;
            // cout << "DBG " <<  last << " " << i << endl;

            // for(int el : res) cout << el << " ";
            // cout << endl;


            for(int j = 1; cur < i; cur ++, j = (j + 1) % (i - last)){
                res[cur] = j + last;
            }

            // for(int el : res) cout << el << " ";
            // cout << endl;

            cur = i + 1;
        }
    }

    int last = cur;
    for(int j = 1; cur < n; cur ++, j = (j + 1) % (n - last)){
        res[cur] = j + last;
    }

    vector<int> freq(n + 1);
    for(int i = 0; i < n; i ++){
        ++ freq[res[i]];
        
        if(res[i] == i and s[i] == '0'){
            cout << "NO\n";
            return;
        }
        if(res[i] != i and s[i] == '1'){
            cout << "NO\n";
            return;
        }
    }

    for(int i = 0; i < n; i ++){
        if(freq[i] != 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(int el : res) cout << el + 1 << " ";
    cout << endl;
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