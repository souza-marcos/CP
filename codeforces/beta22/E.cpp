#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    // Rec the condesed graph 
    // and connect the last node (without out-edges)
    // to the first ones (without in-edges)

    int n; cin >> n;
    vector<vector<int>> g(n), gt(n);
    for(int i = 0; i < n; i ++){
        int a; cin >> a; a--;
        g[i].push_back(a);
    }

    // top ord
    vector<int> color(n, 0), order, cond(n, -1);

    auto dfs1 = [&](auto&& self, int v) -> void{
        color[v] = 1;
        for(int u : g[v]) if(color[v] == 0) self(self, u);

        order.push_back(v);
    };
    for(int i = 0; i < n; i ++){
        if(color[i] == 0) dfs1(dfs1, i);
    }

    reverse(order.begin(), order.end());
    color.resize(n, 0);
    int rep = -1;
    vector<int> reps;
    auto dfs2 = [&](auto&& self, int v) -> void {
        color[v] = 1;
        cond[v] = rep;
        for(int u : gt[v]) if(color[u] == 0) self(self, u);
    };

    for(int i = 0; i < n; i ++){
        if(color[i] == 0){
            rep = i;
            reps.push_back(i);
            dfs2(dfs2, i);
        }
    }

    vector<set<int>> gcondesed(n);
    for(int i = 0; i < n; i ++){
        for(int u : g[i]) if(cond[i] != cond[u]){
            gcondesed[cond[i]].insert(cond[u]);
        } 
    }
    set<int> no_in, no_out;
    for(int idx : reps) no_in.insert(idx);

    for(int idx : reps){
        if(sz(gcondesed[idx]) == 0){
            no_out.insert(idx);
        }

        for(int u : gcondesed[idx]){
            if(no_in.count(u)) no_in.erase(u);
        }
    }

    



} 
