#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int n, l; // Number of nodes and the max jumps of lifting
vector<vector<int>> g;

int timer;
vector<int> tin, tout;
vector<vector<int>> up; // Store the 2^j ancestor of i node

// u is a acestor of v
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

// vertice and its parent
void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;

    for(int i = 1; i <= l; i ++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(int u: g[v])
        if(u != p) dfs(u, v);

    tout[v] = ++timer;
}

int lca(int u, int v){
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = l; i >=0; i--){
        if(!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void load_euler_tour(int root){
    tin.resize(n), tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l+1));
    dfs(root, root);
}


int main(){ _

    return 0;
} 
