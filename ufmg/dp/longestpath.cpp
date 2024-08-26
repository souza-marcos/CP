#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<bool> vis;
vector<int> order;

void dfs(int v){
    vis[v] = true;
    for(int adj: g[v]) if(!vis[adj]) dfs(adj);
    order.push_back(v);
}

int main(){ _
    int n, m; cin >> n >> m;
    g.resize(n);
    vis.assign(n, false);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);

    int dp[n]; 

    int maxpath = 0;
    for(int i = 0; i < order.size(); i++){
        int maxv = 0;
        for(int v: g[order[i]]){
            maxv = max(maxv, dp[v] + 1);
        }
        dp[order[i]] = maxv;
        maxpath = max(maxpath, maxv);
    }

    cout << maxpath << endl;
    return 0;
} 
