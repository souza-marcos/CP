#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()
int n;
vector<vector<int>> g;
const int MAX = 5e5 + 10;
vector<int> res;
vector<bool> vis;

int max_dfs(int v, int dist){
    int maxv = dist;
    vis[v] = true;
    for(int u: g[v]) if(!vis[u]){
        maxv = max(maxv, max_dfs(u, dist + 1));
    }
    // cout << "vertex  "<< v << " " << dist << " " << maxv << endl;
    res[dist] ++;
    res[maxv+1] --;
    return maxv;
}

void solve(){
    cin >> n;
    g.assign(n, {}), vis.assign(n, 0), res.assign(n + 10, 0);
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b), g[b].push_back(a);
    }
    max_dfs(0, 0);

    int maxv = 0, ans = 0, pref = 0;
    // for(auto el: res) cout << el << " ";
    // cout << endl;

    for(int i = 0; i <= n; i ++){
        pref = pref + res[i];
        // cout << pref << " ";
        if(pref > maxv) ans = i, maxv = pref;
    }
    // cout << endl;

    // cout << ans << " " << maxv << endl;
    cout << n - maxv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
    return 0;
} 
