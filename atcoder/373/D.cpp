#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    int u, v, w;
    for(int i = 0; i < m; i ++){
        cin >> u >> v >> w; u--, v--;
        g[u].push_back({v, w}); // out edge
        g[v].push_back({u, -w}); // in edge
    }
    vector<bool> vis(n, false);
    vector<ll> vals(n);
    // BFS
    queue<int> q;
    for(int i = 0; i < n; i ++){
        if(!vis[i]) {
            vals[i] = 0, q.push(i);
            while(!q.empty()){
                int cur = q.front(); q.pop();
                vis[cur] = true;
                for(auto [u, peso]: g[cur]){
                    if(!vis[u]) {
                        q.push(u);
                        vals[u] = vals[cur] + peso;
                    }
                }
            }
        }
    }   

    for(auto el: vals) cout << el << " ";
    cout << endl;
    return 0;
} 
