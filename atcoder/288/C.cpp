#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
vector<vector<int>> g;
vector<bool> vis;


int dfs(int v, int p){
    vis[v] = true;
    int cnt = 0;
    for(auto u: g[v]){
        // if(u == p) continue;
        if(!vis[u]) cnt += dfs(u, v);
        else cnt += 1;
    }
    return cnt;
}

int main(){ _

    int n, m; cin >> n >> m;

    g.assign(n, {});
    vis.assign(n, false);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].push_back(b),
        g[b].push_back(a);
    }


    int cnt = 0;
    for(int i = 0; i < n; i ++){
        if(!vis[i]) cnt += dfs(i, -1);
    }
    cout << cnt - m << endl;
} 
