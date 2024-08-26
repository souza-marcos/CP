#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;

ll memo[51][101];
vector<pair<int, int>> projetil; // dano, cap
ll R; 
int n, k;

ll dp(int i, int cap) {
    if(cap < 0) return -INF;
    if(cap == 0 or i >= n) return 0;

    ll& p = memo[i][cap];
    if(p != -1) return p;
    return p = max(dp(i + 1, cap), dp(i + 1, cap - projetil[i].second) + projetil[i].first); 
}

void solve(){
    memset(memo, -1, sizeof memo);
    cin >> n;
    projetil.assign(n, {});
    for(auto& [dano, cap]: projetil) cin >> dano >> cap;

    int cap_total; cin >> cap_total >> R;

    ll res = dp(0, cap_total);
    // cout << res << endl;

    if(res >= R) cout << "Missao completada com sucesso\n";
    else cout << "Falha na missao\n";
}

int main(){_

    int t; cin >> t;
    while(t --) solve();
    return 0;
}