#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _

    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        vector<int> freq(101);
        for(int i = 0; i < n; i ++){
            int a; cin >> a;
            freq[a] ++;
        }
        sort(freq.rbegin(), freq.rend());
        int res = 0;
        for(int i = 0; i < sz(freq); i ++){
            res = max(res, (i + 1) * freq[i]);
        }
        cout << res << endl;
    }


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