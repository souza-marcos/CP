#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n, k; cin >> n >> k;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < n-1; i ++){
        int a, b, w; cin >> a >> b >> w;
        a --, b--;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    ll dp[n][2]; memset(dp,-1, sizeof dp);

    auto dfs = [&](int v, int p, bool tudo) -> ll {
        auto &res = dp[v][tudo];
        if(res != -1) return res;

        vector<ll> adj;
        for(auto [w, u] : g[v]){
            ll down_all = dfs(u, v, 1), down_no = dfs(u, v, 0);

        }

        return res;
    };

}

int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
