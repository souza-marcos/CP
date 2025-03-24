#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n, s1, s2; cin >> n >> s1 >> s2; s1 --, s2--;
    vector<vector<int>> g(n), h(n);
    vector<set<int>> out(n * n);
    int m1; cin >> m1;
    for(int i = 0; i < m1; i ++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m2; cin >> m2;
    for(int i = 0; i < m2; i ++){
        int a, b; cin >> a >> b; a--, b--;
        h[a].push_back(b);
        h[b].push_back(a);
    }
    map<pair<int, int>, int> where;
    vector<pair<int, int>> from;
    int cnt = 0;
    for(int i = 0; i < n; i ++)
    for(int j = 0; j < n; j ++) 
        where[{i, j}] = cnt ++, from.push_back({i, j}); 

    queue<pair<int, int>> q; q.push({s1, s2});
    set<int> vis;
    while(sz(q)){
        auto [v1, v2] = q.front(); q.pop();
        if(vis.count(where[{v1, v2}])) continue;
        vis.insert(where[{v1, v2}]);

        for(int u1 : g[v1]){
            for(int u2 : h[v2]){
                out[where[{v1,v2}]].insert(where[{u1,u2}]);        
                out[where[{u1,u2}]].insert(where[{v1,v2}]);
                if(vis.count(where[{u1, u2}]) == 0) q.push({u1, u2});
            }
        }
    }

    set<int> endp;

    for(int i = 0; i < n; i ++){
        int v = where[{i, i}]; 
        for(int j = i + 1; j < n; j ++){
            int u = where[{j, j}]; 
            if(out[v].count(u)){
                endp.insert(v), endp.insert(u);
            }
        }
    }

    if(sz(endp) == 0) {
        cout << -1 << endl;
        return;
    }

    // Dijkstra
    vector<int> dist(sz(where), INF);

    priority_queue<pair<int, int>> pq; // -w, v // max heap
    pq.push({-0, where[{s1,s2}]});
    while(sz(pq)){
        auto [w, v] = pq.top(); pq.pop();
        w = -w;
        if(w >= dist[v]) continue;

        dist[v] = w;
        for(auto u : out[v]){
            auto [x, y] = from[u];
            int to_w = w + abs(x - y);
            if(dist[u] > to_w) pq.push({-to_w, u});
        }
    }

    int minv = INF;
    for(int i : endp){
        minv = min(minv, dist[i]);
    }
    cout << minv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
