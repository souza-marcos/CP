#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _

    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b),
        g[b].push_back(a);
    }

    int l = ceil(log2(n));
    vector<vector<int>> up(n, vector<int>(l + 1, -1));
    vector<int> depth(n);
    vector<int> tin(n), tout(n);
    int timer = 0;

    auto dfs = [&](auto&& dfs, int v, int p) -> void {
        tin[v] = timer ++;
        up[v][0] = p;
        for(int i = 1; i <= l; i ++){
            if(up[v][i-1] == -1) break;
            up[v][i] = up[up[v][i-1]][i-1];
        }

        for(auto u : g[v]) if(u != p){
            depth[u] = depth[v] + 1;
            dfs(dfs, u, v);
        }
        tout[v] = timer++;
    };
    depth[0] = 0;
    dfs(dfs, 0, -1);

    auto lca = [&](int a, int b){
        if(depth[a] < depth[b]) swap(a, b);
        int k = depth[a] - depth[b];

        int i = 0;
        while(k > 0){
            if(k&1) a = up[a][i];
            i ++, k >>= 1;
        }

        if(a == b) return a;

        i = l;
        while(i >= 0){
            if(up[a][i] != up[b][i])
                a = up[a][i], b = up[b][i];
            i --;
        }
        return up[a][0];
    };

    auto isanc = [&](int anc, int a) -> bool {
        return tin[anc] <= tin[a] and tout[anc] >= tout[a]; 
    };


    int q; cin >> q;
    while(q--){
        int m; cin >> m;
        vector<int> arr(m); 
        
        for(auto& el : arr) cin >> el, el --;
        sort(arr.begin(), arr.end(), [&](int left, int right){
            return depth[left] > depth[right];
        });

        int lca_all = arr[0];
        for(auto el : arr) lca_all = lca(lca_all, el);

        int p1 = arr[0], p2 = -1;
        bool ok = true;
        for(int i = 1; i < m; i ++){
            int anc = lca(p1, arr[i]);

            if(anc == arr[i]) continue;
            if(anc != lca_all) {
                ok = false;
                break;
            }
            // anc == lca_all => outra branch
            if(p2 == -1){
                p2 = arr[i];
            } else{
                if(!isanc(arr[i], p2)){
                    ok = false;
                    break;
                }
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    } 

    return 0;
} 
