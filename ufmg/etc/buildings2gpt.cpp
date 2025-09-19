#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
#define int ll

int32_t main() {
    _;
    int n, q; cin >> n >> q;
    vector<ll> height(n);
    for(ll &el : height) cin >> el;
    height.push_back(LINF); // sentinel at index n

    // monotonic stack -> parent
    vector<int> st;
    int h = log2(n + 1) + 2;
    vector<vector<int>> up(n + 1, vector<int>(h));
    for(int i = 0; i < n; ++i) up[i][0] = i; // temporary (will be overwritten)
    vector<vector<int>> g(n+1);

    for(int i = 0; i <= n; ++i){
        while(sz(st) && height[st.back()] < height[i]){
            int idx = st.back(); st.pop_back();
            up[idx][0] = i;
            // undirected edges are fine since DFS uses parent to avoid cycle
            g[idx].push_back(i);
            g[i].push_back(idx);
        }
        st.push_back(i);
    }
    up[n][0] = n;

    // build binary lifting table: up[i][j] = 2^j-th ancestor of i
    for(int j = 1; j < h; ++j){
        for(int i = 0; i <= n; ++i){
            up[i][j] = up[ up[i][j-1] ][ j-1 ];
        }
    }

    // val[v] = distance from sentinel n (val[n] = 0)
    vector<int> val(n+1, 0);
    // DFS from sentinel n to fill val (use iterative stack to be safe)
    vector<int> stk; stk.push_back(n);
    vector<int> parent(n+1, -1);
    parent[n] = -1;
    while(!stk.empty()){
        int v = stk.back(); stk.pop_back();
        for(int u : g[v]) if(u != parent[v]){
            parent[u] = v;
            val[u] = val[v] + 1;
            stk.push_back(u);
        }
    }

    // answer queries
    while(q--){
        int l, r; cin >> l >> r; --l; --r; // to 0-based
        int cur = l;
        for(int k = h-1; k >= 0; --k){
            int anc = up[cur][k];
            if(anc <= r) cur = anc;
        }
        // first ancestor with index > r:
        cur = up[cur][0];
        // if cur == n (sentinel) val[n]==0 -> prints 0
        cout << val[cur] << '\n';
    }
    return 0;
}
