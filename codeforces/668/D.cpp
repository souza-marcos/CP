#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n, a, b, da, db;
vector<vector<int>> g;

pair<int, int> dfs(int p, int v, int dis){
    pair<int, int> maxv = {dis, v};
    for(int u: g[v]) 
        if(u != p) maxv = max(maxv, dfs(v, u, dis + 1));
    return maxv;
}

void solve(){
    cin >> n >> a >> b >> da >> db; a--, b--;
    g.assign(n, {});
    for(int i = 1; i < n; i ++){
        int v, u; cin >> v >> u; v --, u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    if(2 * da >= db) {
        cout << "Alice\n";
        return;
    }

    queue<int> q; 
    q.push(a);
    vector<int> dist(n, -1);
    dist[a] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        // cout << cur << " ";
        if(cur == b) break;
        for(int u : g[cur]) 
            if(dist[u] < 0) 
                dist[u] = dist[cur] + 1, q.push(u);  
    }



    if(dist[b] <= da) {  
        cout << "Alice\n";
        return;
    }

    pair<int, int> pt = dfs(-1, 0, 0);
    pair<int, int> res = dfs(-1, pt.second, 0);
    int D = res.first;
    // cout << "Diametro: " << D << endl;
    if(D > 2 * da){
        cout << "Bob\n";
    } else cout << "Alice\n";

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
