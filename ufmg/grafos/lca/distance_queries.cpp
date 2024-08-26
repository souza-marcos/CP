#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

vector<vector<int>> g, up;
vector<int> tin, tout, depth;
int n, l, timer;

void dfs(int v, int p){
    tin[v] = ++timer;

    up[v][0] = p;
    for(int i = 1; i <= l; i++){
        if(up[v][i-1] == -1) break;
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int u: g[v]) if(u != p) depth[u] = depth[v] + 1, dfs(u, v);
    tout[v]= ++timer;
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] and tout[a] >= tout[b];
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;

    for(int i = l; i >= 0; i --){

        if(!is_ancestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

int path_dist(int a, int b){
    int anc = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[anc];
}

int main(){ _

    int q; cin >> n >> q;
    g.resize(n);
    l = ceil(log2(n));
    up.assign(n, vector<int>(l+1, -1));
    tin.resize(n), tout.resize(n);
    int a, b; 
    for(int i = 0; i < n-1; i ++){
        cin >> a >> b; a --, b--;
        g[a].push_back(b);
        g[b].push_back(a); 
    }
    
    depth.resize(n);
    dfs(0, 0);

    while(q --){
        cin >> a >> b; a--, b--;
        cout << path_dist(a, b) << endl;
    }

    // for(auto row: up){
    //     for(auto el: row) cout << el << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for(int el: depth) cout << el << " ";
    // cout << endl;

    return 0;
} 
