#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

// Difference at most one by adjacents.
void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;
    
    bool ok = true;
    for(int i = 1; i < n; i ++)
        if(abs(arr[i] - arr[i-1]) > 1)
            ok = false;

    if(not ok){
        cout << 0 << endl;
        // cout << "a\n";
        return;
    }   

    vector<int> tenta(n);
    bool ainda = false; 
    for(int i = 1; i < n; i ++){
        if(arr[i] - arr[i-1] == 1){
            if(tenta[i-1] == 1){
                cout << 0 << endl;
                // cout << "b\n";
                return;
            }
            tenta[i-1] = -1;
            tenta[i] = -1;
        }
        else if(arr[i] -arr[i-1] == -1){
            if(tenta[i-1] == -1){
                cout << 0 << endl;
                // cout << "c\n";
                return;
            }
            tenta[i-1] = 1;
            tenta[i] = 1;
        }
        else {
            if(tenta[i-1] == -1) tenta[i] = 1;
            else if(tenta[i-1] == 1) tenta[i] = -1;
        }
    }

    for(int i = n-2; i >= 0; i --){
        if(arr[i]-arr[i+1] == 0){ 
            if(tenta[i+1] == 0) continue;
            if(tenta[i] != 0 and tenta[i] == tenta[i+1]){
                cout << 0 << endl;
                // cout << "d\n";
                return;
            }
            
            if(tenta[i+1] == -1) tenta[i] = 1;
            else if(tenta[i+1] == 1) tenta[i] = -1;
            
        }
    }

    for(int i = 0; i < n; i ++) if(tenta[i] == 0) ainda = true;
    
    int res = 0;
    auto test = [&](vector<int> tenta){
        for(int i = 1; i < n; i ++){
            if(arr[i] - arr[i-1] == 1){
                if(tenta[i-1] == 1){
                    return;
                }
                tenta[i-1] = -1;
                tenta[i] = -1;
            }
            else if(arr[i] -arr[i-1] == -1){
                if(tenta[i-1] == -1){
                    return;
                }
                tenta[i-1] = 1;
                tenta[i] = 1;
            }
            else {
                if(tenta[i-1] == -1) tenta[i] = 1;
                else if(tenta[i-1] == 1) tenta[i] = -1;
            }
        }

        vector<int> left(n), right(n); // que são iguais a 1 - R
        for(int i = 0; i < n; i ++){
            left[i] = (i > 0 ? left[i-1] : 0) + (tenta[i] == 1); 
        }

        for(int i = n-1; i >= 0; i --){
            right[i] = (i < n-1 ? right[i+1] : 0) + (tenta[i] == 1); 
        }
        
        bool ok = true;
        for(int i = 0; i < n; i ++){
            // cout << left[i] << " " << right[i] << endl;
            
            int cur = (i - (i > 0 ? left[i-1]: 0)) + (i < n-1 ? right[i+1] : 0) +1;
            // cout << cur << " " << arr[i] << " " << i << " " << endl;
            if(cur != arr[i]) ok = false;
        }
        if(ok) res ++;
    };

    // for(int i = 0; i < n; i ++) cout << tenta[i] << " ";
    // cout << endl;
    // for(int i = 0; i < n; i ++) cout << arr[i] << " ";
    // cout << endl;

    if(not ainda) test(tenta), cout << res << endl;
    else {
        int cur = -1;
        for(int i = 0; i < n; i ++){
            if(tenta[i] == 0) {cur = i; break;}
        }
        tenta[cur] = -1;
        test(tenta);
        tenta[cur] = 1;
        test(tenta);
        cout << res << endl;
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