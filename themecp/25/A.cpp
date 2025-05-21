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
        int u, v; cin >> u >> v;
        u --, v--;
        g[u].push_back(v),
        g[v].push_back(u);
    }

    vector<ll> folhas(n);
    auto dfs = [&](auto&& dfs, int p, int v) -> int {
        int cnt = 0;
        bool ok = false;
        for(auto u : g[v]) if(u != p) ok = true, cnt += dfs(dfs, v, u);
        if(!ok) cnt = 1;
        return folhas[v] = cnt;
    };
    
    dfs(dfs, -1, 0);

    int q; cin >> q;
    while(q --) {
        int x, y; cin >> x >> y;
        x --, y--;
        cout << folhas[x] * folhas[y] << endl;
    }

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
