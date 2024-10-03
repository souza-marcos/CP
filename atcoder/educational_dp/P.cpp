#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()
#define endl '\n'

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
int n;
vector<vector<int>> g;
vector<bool> vis;
int memo[MAXN][2];

pair<int, int> dfs(int v){
    // 0 => Black, 1 => White
    vis[v] = true;
    ll cnt[2] = {1, 1};
    for(int u: g[v]) if(!vis[u]) {
        auto [n0, n1] = dfs(u);
        cnt[0] *= n1;
        cnt[1] *= (n0 + n1)%MOD;
        if (cnt[0]>= MOD) cnt[0] %= MOD;
        if (cnt[1]>= MOD) cnt[1] %= MOD;
    }
    memo[v][0] = cnt[0], memo[v][1]=cnt[1];
    return {memo[v][0], memo[v][1]};
}
int main(){ _
    cin >> n;
    vis.assign(n, false), g.resize(n);
    for(int i = 1; i < n; i ++){
        int v, u; cin >> v >> u;
        v --, u --;
        g[v].push_back(u), g[u].push_back(v);
    }   

    auto [r1, r2] = dfs(0);
    cout << (r1 + r2) % MOD << endl;
    return 0;
} 
