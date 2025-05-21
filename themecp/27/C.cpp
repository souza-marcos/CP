#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> parent(n, -1);
    for(int i = 1; i < n; i ++){
        int p; cin >> p; p--;
        g[i].push_back(p),
        g[p].push_back(i);
        parent[i] = p;
    }

    vector<pair<int, int>> order(n); // order - vertex
    auto dfs = [&](auto&& dfs, int v, int p) -> void {
        for(auto u : g[v]) if(u != p) {
            order[u].second = u;
            order[u].first = order[v].first + 1;
            dfs(dfs, u, v);
        }
    };
    dfs(dfs, 0, -1);
    sort(order.rbegin(), order.rend());

    vector<ll> dp(n), tot(n + 2);
    const int MOD = 998244353;
    for(auto [cur_lay, v] : order){
        ll sum = 0;
        for(int u : g[v]) if(u != parent[v]){
            sum = (sum + dp[u]) % MOD;
        }
        dp[v] = (1 + tot[cur_lay + 1] - sum + MOD) % MOD;
        tot[cur_lay] = (tot[cur_lay] + dp[v]) % MOD;
    }
    cout << (tot[1] + 1) % MOD << endl; 
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
