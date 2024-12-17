#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

vector<vector<int>> g;
vector<int> level;
vector<int> res;

void dfs(int p, int v){
    for(auto u: g[v]){
        if(u == p) continue;
        if(level[u]){
            if(level[v] < level[u]) res.push_back(level[u] - level[v] + 1);
        }else{
            level[u] = level[v] + 1;
            dfs(v, u);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    g.assign(n, {});
    level.assign(n, 0);
    res.clear();
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].push_back(b), g[b].push_back(a);
    }

    level[0] = 1;
    dfs(-1, 0);
    ll ans = 1;
    for(auto el : res) ans *= el;
    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    for(int i = 1; i <= t; i ++) cout << "Case " << i << ": ", solve();

    return 0;
} 
