#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    // Kosaraju
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n), g_reversed(n);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
    
        g_reversed[b].push_back(a);
    }

    vector<int> order;
    vector<int> color(n, 0);
    auto dfs1 = [&](auto&& self, int v) -> void {
        color[v] = 1;
        for(int u : g[v]){
            if(color[u] == 0) self(self, u);
        }
        color[v] = 2;

        order.push_back(v);
    };

    for(int i = 0; i < n; i ++) 
        if(color[i] == 0) dfs1(dfs1, i);

    reverse(order.begin(), order.end());

    int cnt = 0;
    vector<int> comp(n, -1);
    auto dfs2 = [&](auto&& self, int v) -> void {
        color[v] = 1;
        for(int u : g_reversed[v])
            if(color[u] == 0) self(self, u);

        comp[v] = cnt;
    };

    color.assign(n, 0);
    for(int v : order){
        if(color[v] == 0){
            ++ cnt;
            dfs2(dfs2, v);
        }
    }

    cout << cnt << "\n";
    for(auto el : comp)
        cout << el << " ";
    cout << endl;
}