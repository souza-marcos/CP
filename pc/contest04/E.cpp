#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define f first
#define s second
typedef long long ll;

vector<vector<ll>> g;
vector<ll> p;
vector<ll> dist;
vector<bool> vis, path;
pair<ll, ll> maxv; // dist, index
int n, k, c;
ll maxl = -LINF;

void dfs(int v){
    if(dist[v] > maxv.f) maxv.f = dist[v], maxv.s = v;
    for(int u: g[v]) 
        if(dist[u] == -1){
            dist[u] = dist[v] + 1;
            p[u] = v;
            dfs(u);
        }
}

void dfs2(int v, int p){
    vis[v] = true;
    if(v != 0) {
        dist[v] = dist[p] + ((path[v]?-1:1) * k) - c;
    }
    for(auto u: g[v]){
        if(!vis[u]) {
            dfs2(u, v);
        }
    }
    maxl = max(maxl, dist[v]);
}

void solve(){
    cin >> n >> k >> c;
    g.assign(n, {});
    p.assign(n, -1);
    dist.assign(n, -1);
    path.assign(n, 0);
    vis.assign(n, false);

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    p[0] = 0, dist[0] = 0, maxv = {-INF, 0};
    dfs(0);

    int cur = maxv.s, cont = 0;

    while(cur != p[cur]){
        path[cur] = true;
        cur = p[cur];
        cont ++;
    }
    dist.assign(n, 0);
    dist[0] = cont * k;

    // caminho inicial [1 ... maxv.s] e todos estão marcados
    maxl = dist[0];

    dfs2(0, 0);
    cout << maxl << endl;
}

int main(){_

    int t; cin >> t;
    while(t --) solve();
    return 0;
}