#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<vector<int>> g, up;
vector<int> tin, tout, parent;
vector<bool> vis;
int n, k, l, timer = 0;

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] and tout[a] >= tout[b];
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;

    for(int i = l; i >=0 ; i--){
        if(!is_ancestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

void dfs1(int v, int p){
    tin[v] = ++timer;
    
    up[v][0] = p;
    for(int i = 1; i <= l; i ++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u: g[v]) if(u != p) parent[u] = v, dfs1(u, v);

    tout[v] = ++timer;
}

void load_lca(){
    l = ceil(log2(n));
    tin.resize(n), tout.resize(n), parent.resize(n);
    up.assign(n, vector<int>(l, 0));
    dfs1(0, 0);
}

int count(int v, int anc){
    int cnt = 0;
    while(!vis[v]) {
        cnt ++, vis[v] = true;
        if(v == anc or v == 0) break;
        v = parent[v];
    }
    return cnt;
}

int main(){ _
    cin >> n >> k;
    int a, b;

    g.resize(n);
    for(int i = 0; i < n-1; i ++){
        cin >> a >> b;
        a --, b--;
        g[a].push_back(b), g[b].push_back(a);
    }
    load_lca();
    vis.resize(n,false);
    
    // for(auto el: parent) cout << el << " ";
    // cout << endl;

    vector<int> v(k); for(int& el: v) { cin >> el; el --; }
    reverse(v.begin(), v.end());

    if(k == 1) return cout << 1 << endl, 0;

    int anc = lca(v[0], v[1]);
    ll cnt = count(v[0], anc) + count(v[1], anc);
    // cout << "CNT: " << cnt << endl;
    // cout << "LCA("<< v[0] << ", " << v[1] << ") = " << anc << endl;
    v[1] = anc;
    for(int i=1; i < k -1; i ++){
        anc = lca(v[i],v[i + 1]);
        // cout << "LCA("<< v[i] << ", " << v[i + 1] << ") = " << anc << endl;
        cnt += count(v[i + 1], anc);
        // cout << "CNT: " << cnt << endl;
        v[i + 1] = anc;
    }

    cout << cnt << endl;
    return 0;
} 
