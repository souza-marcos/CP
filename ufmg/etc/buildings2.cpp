#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
#define int ll

int32_t main() {

    int n, q; cin >> n >> q;
    vector<ll> height(n); 
    for(ll& el : height) cin >> el;
    height.push_back(LINF);

    vector<int> st;
    int h = log2(n + 1) + 1;
    vector<vector<int>> up(n + 1, vector<int>(h));
    
    for(int i = 0; i < n; i ++)
        up[i][0] = i;

    vector<vector<int>> g(n+1);
    
    
    for(int i = 0; i <= n; i ++){
        while(sz(st) and height[st.back()] < height[i]){
            int idx = st.back();
            st.pop_back();
            up[idx][0] = i;
            g[idx].push_back(i),
            g[i].push_back(idx);
        }
        st.push_back(i);
    }
    up[n][0] = n;

    for(int j = 1; j < h; j ++){
        for(int i = 0; i <= n; i ++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    
    vector<int> val(n+1);
    vector<int> tin(n+1), tout(n+1);
    int timer = 0;
    auto dfs = [&](auto&& self, int v, int p) -> void {
        tin[v] = timer ++;
        for(int u : g[v]) if(u != p){
            val[u] = val[v] + 1;
            self(self, u, v);
        }
        tout[v] = timer ++;
    };

    auto isAncestor = [&](int a, int b) -> bool {
        return tin[a] <= tin[b] and tout[a] >= tout[b]; 
    };

    auto lca = [&](int a, int b) -> int {
        if(isAncestor(a, b)) return a;
        if(isAncestor(b, a)) return b;

        for(int i = h-1; i >= 0; i --){
            if(not isAncestor(up[a][i], b)){
                a = up[a][i];
            }
        }

        return up[a][0];
    };

    dfs(dfs, n, -1);

    while(q--){
        int l, r; cin >> l >> r; l --, r--;
        
        int cur = l;
        for(int k = h-1; k >= 0; --k){
            // cout << cur << " " << k << " " << up.size() << " " << up[0].size() << endl;
            int anc = up[cur][k];
            if(anc <= r) cur = anc;
        }

        cout << val[l]- val[cur]   << endl;
        // cout << val[low] << endl;
    }
    return 0;
}