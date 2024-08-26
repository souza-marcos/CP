#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

vector<int> tin, tout;
vector<vector<pair<int, int>>> g;
vector<vector<ll>> up, minup;
int n, l, timer;

void dfs(int v, int p, ll w){
    tin[v] = ++timer;

    up[v][0] = p;
    minup[v][0] = w;
    for(int i = 1; i <= l; i++){
        minup[v][i] = min(minup[v][i-1], minup[up[v][i-1]][i-1]);
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for(auto [u, peso]: g[v]) if(u != p) dfs(u, v, peso);
    tout[v] = ++timer;
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

ll query(int a, int b){
    int anc = lca(a, b);
    ll res = LINF;
    for(int i = l; i >= 0; i--){
        if(is_ancestor(anc, up[a][i])) res = min(res, minup[a][i]), a = up[a][i];
        if(is_ancestor(anc, up[b][i])) res = min(res, minup[b][i]), b = up[b][i];
    }
    return res;
}

int main(){ _
    int a, b, c;
    cin >> n >> a;

    g.resize(n), tin.resize(n), tout.resize(n);

    for(int i = 1; i <n; i ++){
        cin >> a >> b >> c;
        a --, b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    l = ceil(log2(n));
    up.resize(n, vector<ll>(l+1, -1));
    minup.resize(n, vector<ll>(l+1, LINF));
    dfs(0, 0, LINF);

    int q; cin >> q;
    while(q --){
        cin >> a >> b;
        a --, b--;
        cout << query(a, b) << endl;
    }

    return 0;
} 
