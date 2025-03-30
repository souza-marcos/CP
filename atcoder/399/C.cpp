#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    int n, m; cin >> n >> m;
    vector<bool> vis(n, false);

    vector<vector<int>> g(n);

    int cnt = 0;
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b), g[b].push_back(a);

    }

    auto dfs = [&](auto&& dfs, int v, int p) -> void{
        vis[v] = true;
        for(auto el: g[v]){
            if(el == p) continue;

            if(vis[el]) cnt ++;//, cout << v << " " << el << endl;
            else dfs(dfs, el, v);
        }
    };

    for(int i = 0; i < n; i ++){
        if(!vis[i]) dfs(dfs, i, -1);
    }
    cout << cnt/2<< endl;
    return 0;
} 
