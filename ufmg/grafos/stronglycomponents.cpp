#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 +10;
int n, m;
vector<vector<int>> g(MAX), gt(MAX), adj_scc(MAX);
vector<bool> vis;

vector<int> order, component, rep, root_nodes;

void dfs1(int v){
    vis[v] = true;
    for(int adj: g[v]) if(!vis[adj]) dfs1(adj);
    order.push_back(v);
}

void dfs2(int v){
    vis[v] = true;
    component.push_back(v);
    for(int adj: gt[v]) if(!vis[adj]) dfs2(adj);
}

int main(){ _
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    vis.assign(n, false);
    for(int i = 0; i < n; i++) if(!vis[i]) dfs1(i);

    vis.assign(n, false);
    reverse(order.begin(), order.end());


    rep.assign(n, 0);
    // Na ordem topologica
    for(int v : order) if(!vis[v]) {
        dfs2(v); // Processando em gt e adicionando no componente

        // for(int sv: component) cout << sv  + 1 << " ";
        // cout << endl;

        int root = component.front();
        for(int sv : component) rep[sv] = root; // Dividindo em DSU
        root_nodes.push_back(root);

        component.clear();
    }

    for(int i = 0; i < n; i++){
        for(int u : g[i]){
            int root_par = rep[i], root_cur = rep[u];

            if(root_par != root_cur) adj_scc[root_par].push_back(root_cur);
        }
    }

    cout << "Representantes dos SCC: ";
    for(int reps: root_nodes) cout << reps + 1<< " ";
    cout << endl;

    for(int i = 0; i < adj_scc.size(); i++){
        for(int u : adj_scc[i]) cout << i + 1 << " " << u + 1 << endl; 
    }


    return 0;
} 
