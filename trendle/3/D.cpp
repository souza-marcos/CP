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

    for(int i=1;i<n;i++){
        int a, b, w; cin >> a >> b >> w;
        a --, b--;
        g[a].push_back({w, b}); 
        g[b].push_back({w, a});
    }

    // 0 -> pego k melhores edges, 1 -> k-1
    vector<vector<ll>> dp(n, vector<ll>(2, -1)); // memset(dp, -1, sizeof dp);

    auto dfs = [&](auto&& self, int v, int p) -> void {
        if(dp[v][0] != -1) return ;

        vector<tuple<ll, ll, ll>> adj;
        // ll wparent=0;
        for(auto [w, u]: g[v]){
            if(u == p) continue;
            
            self(self, u, v);
            adj.push_back({
                dp[u][1] + w - dp[u][0],
                dp[u][1] + w,
                dp[u][0]
            });
        }

        sort(adj.rbegin(), adj.rend());
        // Pega a k-1 melhores > 0
        ll sum = 0;
        int i = 0;
        for(; i < min(k-1, sz(adj)); i ++){
            if(get<0>(adj[i]) < 0) break;
            sum += get<1>(adj[i]);
        }
        ll rest= 0;
        for(int j = i; j < sz(adj); j ++) 
            rest += get<2>(adj[j]);

        dp[v][1] = sum+rest;
        
        if(k-1 <= sz(adj)-1 and get<0>(adj[k-1]) >= 0) 
            sum += get<1>(adj[k-1]), rest -= get<2>(adj[k-1]); 
        
        dp[v][0] = sum + rest;
    };

    dfs(dfs, 0, -1);

    cout << max(dp[0][0], dp[0][1]) << endl;

    // auto d2 = [&](auto&& d2, int v, int p) -> void {
    //     cout << v << " => " << dp[v][0] << " " << dp[v][1] << endl;
    //     for(auto [w, u] : g[v]){
    //         if(u == p) continue;
    //         d2(d2, u, v);
    //     }
    // };

    // d2(d2, 0, -1);

}

int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
