#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

vector<vector<int>> g, up;
vector<bool> vis;
int n, l = log2(1e9 + 10);

void dfs(int v, int p){
    vis[v] = true;
    up[v][0] = p;
    for(int i = 1; i <= l; i ++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u: g[v]) if(!vis[u]) dfs(u, v);
}

int main(){ _
    int q; cin >> n >> q;
    
    g.resize(n);
    for(int i=0; i < n; i ++){
        int a; cin >> a; a --;
        g[a].push_back(i);
    }

    for(int i = 0; i < n; i ++) if(!vis[i]) dfs();

    return 0;
} 
