#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    int n, x, y; cin >> n >> x >> y; x --, y--;
    vector<vector<int>> g(n);

    for(int i = 0; i < n; i ++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b),
        g[b].push_back(a);
    }


    vector<bool> cycle(n), vis(n);
    vector<int> parent(n, -1);
    int start = -1, endc = -1;

    auto dfs = [&](auto&& dfs, int v, int p) -> void {
        vis[v] = true;
        parent[v] = p;
        for(auto u : g[v]){
            if(u == p) continue;

            if(!vis[u]) dfs(dfs, u, v);
            else start = v, endc = u;
        }
    };

    dfs(dfs, 0, -1);

    int cur = endc;
    cycle[endc] = cycle[start] = true;
    while(cur != start){
        cycle[cur] = true;
        cur = parent[cur];
    }

    if(x == y) { cout << "NO\n"; return;}
    if(cycle[y]) { cout << "YES\n"; return;}

    vector<int> distm(n, INF);
    queue<int> q; q.push(x);
    distm[x] = 0;
    while(sz(q)){
        int cur = q.front(); q.pop();
        for(auto u : g[cur]){
            if(distm[u] == INF){
                distm[u] = distm[cur] + 1;
                q.push(u);
            }
        }
    }

    // for(auto el : cycle) cout << el << " ";
    // cout << endl;

    // for(auto el : distm) cout << el << " ";
    // cout << endl;


    vector<int> distv(n, INF);
    distv[y] = 0;
    // cout << y << " => " << 0 << endl;;
    q.push(y);
    while(sz(q)){
        int cur = q.front(); q.pop();
        // cout << cur << " => " << distv[cur] << "  " << distm[cur] << endl;
        if(cycle[cur]) {
            cout << "YES\n";
            return;
        }
        for(auto u : g[cur]){
            if(distv[u] == INF and distv[cur] + 1 < distm[u]){
                distv[u] = distv[cur] + 1;
                q.push(u);
            }
        }
    }
    cout << "NO\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
