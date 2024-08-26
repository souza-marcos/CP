#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

vector<vector<int>> g, up;
vector<int> tin, tout;
int n, l, timer;

void dfs(int v, int p){
    tin[v] = ++timer;

    up[v][0] = p;
    for(int i = 1; i <= l; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(int u: g[v]) if(u != p) dfs(u, v);
    tout[v] = ++timer;
}

// Is a ancestor of b?
bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] and tout[a] >= tout[b];
}

// lowest common ancestor of a and b
int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;

    for(int i = l; i >= 0; i --){
        if(!is_ancestor(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

int main(){ _
    int q; cin >> n >> q;
    l = ceil(log2(n));
    tin.resize(n), tout.resize(n);
    up.assign(n, vector<int>(l + 1, -1));
    g.resize(n);

    for(int i = 1; i < n; i ++){
        int a; cin >> a; a --;
        g[i].push_back(a);
        g[a].push_back(i);
    }
    dfs(0, 0);

    while(q --){
        int a, b; cin >> a >> b;
        a --, b--;
        cout << lca(a, b) + 1 << endl;
    }
    return 0;
} 
