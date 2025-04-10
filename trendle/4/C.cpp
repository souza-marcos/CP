#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    int n, m; cin >> n >> m;
    vector<int> vis(n, 0);
    vector<vector<int>> g(n);

    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[b].push_back(a);
    }

    for(auto& row : g) sort(row.begin(), row.end());

    vector<int> res;
    auto dfs = [&](auto&& dfs, int v) -> void {
        cout << v << " ";
        vis[v] = 1;
        for(int u: g[v]){
            if(vis[u] == 1){
                cout << -1 << endl;
                exit(0);
            }
            if(vis[u] == 0) dfs(dfs, u);
        }
        vis[v] = 2;
        res.push_back(v);
    };

    for(int i = 0; i < n; i ++){
        if(vis[i] == 0) dfs(dfs, i);
    }

    cout << endl;
    for(auto el: vis) cout << el + 1 << " ";
    cout << endl;

} 
