// https://codeforces.com/contest/1902/standings/friends/true
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int n, h;
vector<int> arr;
vector<vector<int>> g;
vector<vector<int>> up;

int timer = 0;
vector<int> tin, tout;
vector<vector<int>> util;

void dfs1(int v, int p){
    tin[v] = timer++;

    up[v][0] = p;
    for(int j = 1; j < h; j ++)
        up[v][j] = up[up[v][j-1]][j-1];

    for(int u : g[v]) {
        if(u != p) {
            dfs1(u, v);
        }
    }
    tout[v] = timer++;
}

vector<int> basis;

bool add(int a){
    for(int b : basis) a = min(a, a^b);
    if(a) basis.push_back(a);
    return a != 0; 
}

// "Basis" for each vertice
void dfs2(int v, int p){
    vector<int> cur = {v};
    basis.clear();
    add(arr[v]); 
    for(int el : util[p]) if(add(arr[el])) cur.push_back(el);
    util[v] = cur;

    for(int u : g[v]) if(u != p) dfs2(u, v);
}

bool isAncestor(int a, int b){
    return tin[a] <= tin[b] and tout[a] >= tout[b];
}

int lca(int a, int b){
    if(isAncestor(a, b)) return a;
    if(isAncestor(b, a)) return b;

    for(int i = h-1; i >= 0; i --){
        if(not isAncestor(up[a][i], b)){
            a = up[a][i];
        }
    }

    return up[a][0];
}

bool query(int a, int b, int x){
    int low = lca(a, b);

    basis.clear();
    for(int u : util[a]){
        if(not isAncestor(u, low)){ // tá pra baixo
            add(arr[u]);
        }
    }
    
    for(int u : util[b]){
        if(not isAncestor(u, low)){ // tá pra baixo
            add(arr[u]);
        }
    }
    
    add(arr[low]);
    return not add(x);
}

int main(){  _
    cin >> n;
    h = log2(n)+1;
    g.resize(n, {});
    arr.resize(n);

    util.resize(n, {});

    for(int i = 0; i < n; i ++) cin >> arr[i];
    for(int i = 0; i < n-1; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    tin.resize(n), tout.resize(n);
    up.assign(n, vector<int>(h));
    dfs1(0, 0);

    // Quero armazenar para cada vertice uma base mas com elementos mais baixos possiveis.]
    // A base eh de no maximo 20 numeros.
    dfs2(0, 0);
    int q; cin >> q;
    while(q --){
        int a, b, k; cin >> a >> b >> k;
        a--, b--;
        cout << (query(a, b, k)?"YES\n":"NO\n");
    }
    return 0;
} 
