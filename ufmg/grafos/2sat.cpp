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
    vis.assign(n, 0), rep.assign(n, -1);

    for(int i = 0; i < n; i ++) if(!vis[i]) dfs1(i);

    reverse(order.begin(), order.end());
    for(int i = 0; i < n; i ++) {
        int u = order[i];
        if(rep[u] == -1) dfs2(u, i); // colocamos o representante como a "posicao" na ordem topologica 
    }

    assig.assign(n/2, false); // variables
    for(int i = 0; i < n; i += 2){
        int repa = rep[i], repb = rep[i + 1];
        if(repa == repb) return false; // Literais no mesmo SCC

        assig[i/2] = repb < repa;  // Verdade, se E ~x ~> x logo x=1 => 0 ~> 1 
    }
    return true;

}

// 00000        
//     1 ^
// 00001


// tranforma disjuncao em implicativa. (~a v b) => (a -> b) ^ (~b -> ~a)
void add_disjunction(int a, bool na, int b, bool nb){

    a = (a << 1) ^ na; 
    b = (b << 1) ^ nb;

    int neg_a = a ^ 1, neg_b = b ^ 1;

    g[neg_a].push_back(b);
    g[neg_b].push_back(a);

    gt[b].push_back(neg_a);
    gt[a].push_back(neg_b);
} 

