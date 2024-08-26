#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 7;


int main(){ _
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> g(n);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, 0));
    const int mod = 1e9 + 7;
    dp[0][1] = 1;
    for(int mask = 1, L = 1 << n; mask < L; mask += 2) {
        for(int u = 0; u < n; u++) if(mask >> u & 1) {
            for(int v : g[u]) if(!(mask >> v & 1)) {
                int &ret = dp[v][mask | (1 << v)] += dp[u][mask];
                if(ret >= mod) ret -= mod;
            }
        }
    }
 

    cout << dp.back().back() << endl;
    return 0;
} 
