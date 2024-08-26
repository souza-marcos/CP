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

int n, m; 
vector<vector<int>> g;
int memo[1<<19][20];

ll dp(int cur, int mask){
    // cout << cur << " " << mask << endl;
    if(mask == ((1 << (n-1)) - 1)) return (cur == (n-1)); 
    int& p = memo[mask][cur];
    
    if(p != 0) return p-1;

    ll ans = 0;
    for(auto el: g[cur]){
        if(el == 0 or ((1 << (el-1)) & mask)) continue; // Já visto
        ans += dp(el, mask | (1 << (el-1)));
        ans %= MOD;
    }
    p = ans + 1;
    return ans;
}

int main(){ _
    cin >> n >> m;
    g.resize(n);


    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }

    cout << dp(0, 0) << endl;
    return 0;
} 
