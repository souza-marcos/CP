#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll


int32_t main(){ _ 
    int n; cin >> n;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;

    int res = 0;
    vector<bitset<64>> ans;
    for(int tenta = 0; tenta < (1 << n); tenta ++){
        vector<int> left(n), right(n); // que são iguais a 1 - R
        for(int i = 0; i < n; i ++){
            left[i] = (i > 0 ? left[i-1] : 0) + (tenta & (1 << i)); 
        }

        for(int i = n-1; i >= 0; i --){
            right[i] = (i < n-1 ? left[i+1] : 0) + (tenta & (1 << i)); 
        }

        bool ok = true;
        for(int i = 0; i < n; i ++){
            int cur = (i - (i > 0 ? left[i-1] : 0)) + (i < n-1 ? right[i+1] : 0) +1;
            cout << cur << " " << arr[i] << " " << i << " " << endl;
            if(cur != arr[i]) ok = false;
        }
        if(ok) res ++, ans.push_back(bitset<64>(tenta));
    }

    cout << res << endl;
    for(auto el : ans) cout << el << "\n";
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