#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

vector<vector<int>> g, up;
int n, l;
void dfs(int v, int p){

    up[v][0] = p;
    for(int i = 1; i <= l; i++){
        if(up[v][i-1] == -1) break;
        up[v][i] = up[up[v][i-1]][i-1];
    } 
    for(auto u: g[v]) if(u != p) dfs(u, v);
}

// k-th ancestor of vertice v
int query(int v, int k){
    int at = v;
    for(int i = 0; i <= l; i++){
        if(k & (1 << i)){
            if(at == -1) break;
            at = up[at][i];
        }
    }
    return ((at == -1)? at: at + 1);
}

int main(){ _
    cin >> n;
    up.assign(n, vector<int>(l + 1, -1));
    g.resize(n);
    int q; cin >> q;
    for(int i = 1; i < n; i ++){
        int a; cin >> a; a--;
        g[i].push_back(a);
        g[a].push_back(i);
    }

    dfs(0,-1);

    // for(auto row: up){
    //     for(auto el: row) cout << el << " ";
    //     cout << endl;
    // }

    while(q --){
        int u, k; cin >> u >> k; u--;
        cout << query(u, k) << endl;
    }

    return 0;
} 
