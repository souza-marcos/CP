// https://codeforces.com/problemset/problem/2131/D
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int leaves = 0;
    for(int i = 0; i < n; i ++){
        if(sz(g[i]) == 1) leaves += 1;
    }

    int res = INF;
    for(int i = 0; i < n; i ++){
        int cnt= 0;
        for(int u : g[i]) cnt += sz(g[u]) == 1; 
        res = min(res, leaves - cnt);
    }

    if(n <= 3) cout << 0 << endl;
    else cout << res << endl;    
}

int32_t main(){ _ 
    int t; cin >> t;
    while (t --) solve();
}
