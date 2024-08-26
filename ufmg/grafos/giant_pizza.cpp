#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


vector<vector<int>> g, gt;
vector<bool> vis, assig;
vector<int> rep, order;

void dfs1(int v){
    vis[v] = true;
    for(int u : g[v]) if(!vis[u]) dfs1(u);
    order.push_back(v);
}

void dfs2(int v, int root){
    rep[v] = root;
    for(int u : gt[v]) if(rep[u] == -1) dfs2(u, root);
}

int main(){ //_
    int n, m; scanf("%d %d\n", &m, &n);
    g.resize(2 * n), gt.resize(2 * n);

    for(int i = 0; i < m; i++){
        char type_a, type_b; int a, b;
        scanf("%c %d %c %d\n", &type_a, &a, &type_b, &b); a--, b--;
        a = a<<1 ^ (type_a == '-'), b = b<<1 ^ (type_b == '-');
        int nega = a ^ 1, negb = b ^ 1;

        g[nega].push_back(b);
        g[negb].push_back(a);

        gt[b].push_back(nega);
        gt[a].push_back(negb); 
    }

    vis.assign(2 * n, false);
    for(int i = 0; i < 2 * n; i++) if(!vis[i]) dfs1(i);

    reverse(order.begin(), order.end());
    rep.assign(2 * n, -1);
    for(int i = 0; i < 2 * n; i++) if(rep[order[i]] == -1) dfs2(order[i], i);

    assig.assign(n, 0);
    for(int i = 0; i < 2 * n; i+= 2){
        int repa = rep[i], repb = rep[i + 1];
        if(repa == repb){ cout << "IMPOSSIBLE\n"; exit(0); }
        assig[i/2] = repb < repa;
    }

    for(bool topp : assig) cout << (topp?"+":"-") << " ";
    cout << endl;

    return 0;
} 
