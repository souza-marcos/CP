#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
vector<pair<int, int>> p; // qtd de brinq, peso

int memo[110][60];
pair<int, int> res[110][60];

// N_MAX brinq, PESO usado, PACOTES USADOS
tuple<int, int, int> dp(int n, int cap){
    if(cap < 0) return {-INF, 0, 0};
    if(n == p.size()) return {0, 0, 0};
    int &memo_brin = memo[n][cap];
    auto& [memo_peso, memo_paco] = res[n][cap];

    if(memo_brin != -1) 
        return {
            memo_brin, 
            memo_peso, 
            memo_paco
        };

    auto [qtd_ad, peso_ad, pac_ad] = dp(n + 1, cap - p[n].second);
    qtd_ad += p[n].first;
    peso_ad += p[n].second;
    pac_ad ++;

    auto [qtd_lea, peso_lea, res_lea] = dp(n + 1, cap);

    if(qtd_ad > qtd_lea){
        memo_brin = qtd_ad, memo_peso = peso_ad, memo_paco = pac_ad;
        return {qtd_ad, peso_ad, pac_ad};
    }   
    
    memo_brin = qtd_lea, memo_peso = peso_lea, memo_paco = res_lea;
    return {qtd_lea, peso_lea, res_lea};
}

void solve(){
    int pac; cin >> pac;
    p.assign(pac, {});
    for(auto& [n, peso]: p){
        cin >> n >> peso;
    }
    
    memset(memo, -1, sizeof memo);
    auto [b, peso, qtd] = dp(0, 50);
    cout << b << " brinquedos\nPeso: " << peso << " kg\nsobra(m) " << pac - qtd << " pacote(s)\n"; 
}

int main(){_

    int t; cin >> t;
    while(t --) { solve(); cout << (t?"\n":""); }
    return 0;
}