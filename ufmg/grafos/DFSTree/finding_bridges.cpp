#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

vector<vector<int>> g;
vector<int> dp;
vector<bool> vis;
set<pair<int, int>> marked;

vector<pair<int, int>> bridges;

int dfs(int p, int v){
    vis[v] = true;
    int back_edges_up = 0, back_edges_down = 0, sum = 0;
    for(auto u: g[v]){
        if(u == p) continue;
        if(vis[u]){
            if(marked.count({v, u})) back_edges_down ++;
            else back_edges_up ++, marked.insert({u, v});
        }
        else {
            int val = dfs(v, u);
            if(val == 0) bridges.push_back({v,u});
            sum += val;
        }
    }
    dp[v] = back_edges_up - back_edges_down + sum;
    return dp[v];
}   


int main(){ _
    int n, m; cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp.assign(n, 0);
    vis.assign(n, false);
    dfs(-1, 0);
    cout << "Bridges: \n";
    for(auto [u, v] : bridges){
        u ++, v ++;
        cout << u << " " << v << endl;
    }
    cout << endl;
    return 0;
} 
