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
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for(int u: g[v]) if(u != p){
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
    tout[v]= ++timer;
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] and tout[a] >= tout[b];
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;

    for(int i = l; i >= 0; i--){
        if(!is_ancestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

int query(int in, int out, int ener){
    int anc = lca(in, out), dist = depth[in] + depth[out] - 2 * depth[anc];
    if(dist <= ener) return out;

    int d1 = depth[in] - depth[anc];
    if(d1 == ener) return anc;
    if(d1 > ener) {
        for(int i = 0; i <= ceil(log2(ener)); i ++){
            if(ener & (1 << i)){
                in = up[in][i];
            }
        }
        return in;
    }
    ener -= d1;
    ener = (depth[out] - depth[anc]) - ener;

    for(int i = 0; i <= ceil(log2(ener)); i++){
        if(ener & (1 << i)){
            out = up[out][i];
        }
    }
    return out;

}

int main(){ _

    cin >> n;
    l = ceil(log2(n));
    g.resize(n), tin.resize(n), tout.resize(n), depth.resize(n), up.assign(n, vector<int>(l + 1, -1));
    int a, b;
    for(int i = 1; i < n; i++){
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);

    int q; cin >> q;
    while(q --){
        int in, out, ener; cin >> in >> out >> ener;
        in --, out --;
        cout << query(in, out, ener) + 1 << endl;
    }

    // for(auto row: up){
    //     for(auto el: row) cout << el << " ";
    //     cout << endl;
    // }

    // for(auto el: depth) cout << el << " ";
    // cout << endl;

    return 0;
} 
