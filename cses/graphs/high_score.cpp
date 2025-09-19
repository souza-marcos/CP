#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int32_t main(){ _ 
// Bellman-Ford with negative edges

    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    vector<ll> weight;
    vector<vector<pair<int, ll>>> g(n);

    for(int i = 0; i < m; i ++){
        int a, b, c; cin >> a >> b >> c;
        a --, b--, c *= -1;
        g[a].push_back({b, c});
        edges.push_back({a, b});
        weight.push_back(c);    }

    vector<int> color(n, 0);
    auto dfs = [&](auto&& self, int v) -> void {
        color[v] = 1;
        for(auto [u, w] : g[v]) 
            if(color[u] == 0) self(self, u);
    };
    dfs(dfs, 0);

    vector<ll> d(n, LINF);
    d[0] = 0;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            auto [a, b] = edges[j];
            if(color[a] == 0) continue;
            if(d[b] > d[a] + weight[j]){
                d[b] = d[a] + weight[j];
            }
        }
    }

    vector<int> cycle;

    for(int j = 0; j < m; j ++){
        auto [a, b] = edges[j];
        if(color[a] == 0) continue;
        if(d[b] > d[a] + weight[j]){
            cycle.push_back(a);
            d[b] = d[a] + weight[j];
        }
    }
    color.assign(n, 0);

    auto dfs2 = [&](auto&& self, int v) -> void {
        color[v] = 1;
        for(auto [u, w] : g[v]) if(color[u]==0) self(self, u);
    };
 
    for(int i : cycle) if(color[i] == 0) dfs2(dfs2, i);
    if(color[n-1] == 0)
        cout << -d[n-1] << endl;
    else cout << -1 << endl;
}