// https://judge.beecrowd.com/pt/problems/view/2087
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) (int)x.size()

int solve(int t){
    vector<string> lista(t);
    for(auto& s: lista) cin >> s;
    sort(lista.begin(), lista.end());

    for(int i = 0; i < t-1; i++){
        auto& cur = lista[i];
        auto& nxt = lista[i + 1];

        bool ok = false;
        for(int j = 0; j < sz(cur); j ++){
            if(cur[j] != nxt[j]) {
                ok = true;
                break;
            }
        }
        if(!ok) return cout << "Conjunto Ruim\n", 0;
    }
    cout << "Conjunto Bom\n";
    return 0;
}
int main(){
    int t;
    while(cin >> t and t != 0) solve(t);
}