#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
int n, m;
vector<vector<int>> g(MAX), gt(MAX);

vector<int> order, comp, rep;
vector<bool> vis;

void dfs1(int v){
    vis[v] = true;
    for(int u : g[v]) if(!vis[u]) dfs1(u);
    order.push_back(v);
}


void dfs2(int v){
    vis[v] = true;
    for(int u : gt[v]) if(!vis[u]) dfs2(u);
    comp.push_back(v);
}

int main(){ _
    cin >> n >> m;
    rep.resize(n);
    iota(rep.begin(), rep.end(), 0);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    vis.assign(n, false);

    for(int i = 0; i < n; i++) if(!vis[i]) dfs1(i);

    vis.assign(n, false);
    reverse(order.begin(), order.end());

    int ncomp = 0;
    for(int v : order) if(!vis[v]){
        dfs2(v);
        int root = comp.front();
        for(int u: comp) rep[u] = root;
        comp.clear();
        ncomp ++;
    }

    // for(auto it : rep) cout << it << " ";
    // cout << endl;

    if(ncomp > 1){
        cout << "NO\n";

        for(int i = 0; i < n; i++){
            for(int u: g[i]){
                int repa = rep[i], repb = rep[u];
                if(repa != repb){
                    cout << repb + 1 << " " << repa + 1 << endl;
                    return 0;
                }
            }
        }
        for(int i = 0; i < n - 1; i++){
            int repa = rep[i], repb = rep[i + 1];
            if(repa != repb){
                cout << repb + 1 << " " << repa + 1 << endl;
                return 0;
            }
        }
    }else cout << "YES\n";

    return 0;
} 
