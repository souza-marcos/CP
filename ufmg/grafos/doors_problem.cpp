#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<vector<int>> g, gt;
vector<int> order, rep;
vector<bool> vis, assig;


void dfs1(int v){
    vis[v] = true;
    for(int u : g[v]) if(!vis[u]) dfs1(u);
    order.push_back(v);
}

void dfs2(int v, int root){
    rep[v] = root;
    for(int u : gt[v]) if(rep[u] == -1) dfs2(u, root);
}

bool solve2sat(){
    order.clear();
    vis.assign(2*n, 0), rep.assign(2*n, -1);

    for(int i = 0; i < 2*n; i ++) if(!vis[i]) dfs1(i);

    reverse(order.begin(), order.end());
    for(int i = 0; i < 2*n; i ++) {
        int u = order[i];
        if(rep[u] == -1) dfs2(u, i); // colocamos o representante como a "posicao" na ordem topologica 
    }

    assig.assign(n, false); // variables
    for(int i = 0; i < 2*n; i += 2){
        int repa = rep[i], repb = rep[i + 1];
        if(repa == repb) return false; // Literais no mesmo SCC

        assig[i/2] = repb < repa;  // Verdade, se E ~x ~> x logo x=1 => 0 ~> 1 
    }
    return true;

}

// 00000        
//     1 ^
// 00001

void impl(int a, bool na, int b, bool nb){
    a = (a << 1) ^ na; 
    b = (b << 1) ^ nb;
    
    int nega = a ^ 1, negb = b ^ 1;

    g[a].push_back(b);
    g[negb].push_back(nega);

    gt[b].push_back(a);
    gt[nega].push_back(negb);
}

int main(){

    cin >> m >> n;
    vector<tuple<bool, int, int>> rooms;
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        rooms.push_back({a, -1, -1});
    }
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        for(int j = 0; j < t; j++){
            int index; cin >> index; index --;
            auto &[val, a, b] = rooms[index];
            if(a == -1) a = i;
            else b = i;
        }
    }

    g.assign(2*n, {}), gt.assign(2*n, {});

    for(auto [val, a, b] : rooms){
        // val == 0 => (a -> ~b) ^ (~a -> b) ^ (b -> ~a) ^ (~b -> a)
        // val == 1 => (a -> b) ^ (~a -> ~b) ^ (b -> a) ^ (~b -> ~a)
        if(!val) impl(a, 1, b, 0), impl(a, 0, b, 1);
        else impl(a, 1, b, 1), impl(a, 0, b, 0);
    }

    // for(int i = 0; i < 2 * n; i++) for(int u: g[i]) cout << i << " - " << u << endl;

    cout << (solve2sat()? "YES":"NO") << endl;

    // for(bool val : assig) cout << val << " ";
    // cout << endl;

    return 0;
}


