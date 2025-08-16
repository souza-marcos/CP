#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

vector<vector<int>> g;
vector<bool> vis;
vector<int> res;
int n, m, x, y; 

bool dfs(int v){
    vis[v] = true;
    if(v == y) return true;
    for(int u : g[v]){
        if(vis[u] == 0 and dfs(u)){
            res.push_back(u);
            return true;
        }
    }    
    return false;
}

void solve(){
    cin >> n >> m >> x >> y; x--, y--;

    g.assign(n, {});
    vis.assign(n, false);
    res.clear();
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; i ++){
        sort(g[i].begin(), g[i].end());
    }
    dfs(x);
    res.push_back(x);
    reverse(res.begin(), res.end());
    for(auto el: res) cout << el + 1 << " ";
    cout << endl;
}

int main(){ _ 

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
