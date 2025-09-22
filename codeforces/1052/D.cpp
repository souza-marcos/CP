#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){

    int l, r; cin >> l >> r;
    int el = 1;
    while(el*2 <= r+1) el <<= 1;



    int n = r-l+1;
    {
        cout << n * (n-1) << endl;;
    }
    vector<int> res(n), used(n, -1);

    for(int i = el-1; i >= l; i --){
        if(used[i] != -1){
            res[i] = used[i];
            continue;
        }
        int aux=0;
        while(aux < i) aux <<= 1, aux |= 1;
        int quero = aux ^ i;
                
        // cout << i << " " << quero << endl;;
        // assert(used[quero] != 1);
        used[quero]=i;
        used[i] = quero;
        res[i]=quero;
    }

    vector<int> vec;
    for(int i = el; i <= r; i ++){
        // troca
        int j = i ^ el;
        res[used[j]] = i;
        vec.push_back(j);
    }
    sort(vec.begin(), vec.end());
    // cout << sz(vec) << endl;

    for(int i = el; i <= r; i++)
        res[i] = vec.back(), vec.pop_back();

    ll tot = 0;
    for(int i = 0; i < n; i ++){
        tot += res[i] | i;
    }
    cout << tot << endl;
    for(int i : res) cout << i << " ";
    cout << endl;
}

int32_t main(){ _
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