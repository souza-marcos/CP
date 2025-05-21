#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _

    int n, q; cin >> n >> q;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].push_back(b),
        g[b].push_back(a);
    }
    int l = ceil(log2(n));
    vector<vector<int>> up(n, vector<int>(l + 1, -1));
    vector<int> depth(n);
    
    auto dfs = [&](auto&& dfs, int v, int p) -> void {
        up[v][0] = p;

        for(int i = 1; i <= l; i ++){
            if(up[v][i-1] == -1) break;
            up[v][i] = up[up[v][i-1]][i-1];
        }

        for(auto u : g[v]) if(u != p){
            depth[u] = depth[v] + 1;
            dfs(dfs, u, v);    
        }
    };
    dfs(dfs, 0, -1);

    auto lca = [&](int a, int b) -> int {
        if(depth[a] < depth[b]) swap(a, b);

        int k = depth[a] - depth[b];
        int i = 0;
        while(k > 0){
            if(k&1) a = up[a][i]; 
            i ++, k >>= 1;
        }
        
        if(a == b) return a;

        i = l;
        while(i --){
            if(up[a][i] != up[b][i]){
                a = up[a][i],
                b = up[b][i];
            }
        }
        return up[a][0];
    };

    while(q --){
        int k; cin >> k;
        int cur = 0;
        vector<int> arr(k); 
        for(auto& el : arr) {
            cin >> el; el --;
            cur = (depth[cur] > depth[el] ? cur : el);
        }
        bool ok = true;
        for(int i = 0; i < k; i ++){
            // Check the condition
            int anc = lca(cur, arr[i]); 
            if(anc != arr[i] and anc != up[arr[i]][0])
                ok = false;
        }
        cout << (ok? "YES\n" : "NO\n");
    }
    return 0;
} 
