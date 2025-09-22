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
    for(int i = 0; i < n-1; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b),
        g[b].push_back(a);
    }

    vector<int> dp(n), szo(n);
    
    auto dfs = [&](auto&& self, int v, int p) -> void {
        int cur = 1;
        vector<int> adj;
        for(int u : g[v]) if(u != p){
            self(self, u, v);
            cur += szo[u];
            adj.push_back(u);
        }

        if(sz(adj) > 1)
            dp[v] = max(szo[adj[0]]-1 + dp[adj[1]], szo[adj[1]]-1 + dp[adj[0]]);
        else if(sz(adj) > 0)
            dp[v] = szo[adj[0]]-1;
            
        szo[v] = cur;

        // cout << v+1 << " " << szo[v] << " " << dp[v] << endl;
    };  
    // cout << "------\n";
    dfs(dfs, 0, -1);
    cout << dp[0] << endl;
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
