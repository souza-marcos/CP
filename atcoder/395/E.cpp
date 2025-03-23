#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    
    int n, m, x; cin >> n >> m >> x;
    vector<pair<int, int>> edges(m); for(auto &[v, u] : edges) cin >> v >> u;
    vector<vector<pair<int, int>>> g(2*n + 2);

    for(auto [v, u]: edges) {
        g[2*v].push_back({2*u, 1});
        g[2*u+1].push_back({2*v+1, 1});
    }
    for(int i = 1; i <= n; i ++){
        g[2*i].push_back({2*i+1, x});
        g[2*i+1].push_back({2*i, x});
    }

    // dijkstra 1 -> n
    vector<ll> dist(2*n + 2, LINF);
    priority_queue<pair<ll, int>> pq; // -w, v
    pq.push({-0, 2});

    while(sz(pq)){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        
        if(dist[v] <= d) continue;
        dist[v] = d;
        for(auto [u, w]: g[v]){
            ll newd = d + w;
            if(dist[u] > newd) pq.push({-newd, u});
        }

    }

    // for(auto d: dist) cout << d << " ";
    // cout << endl;

    // for(int i = 1; i <= n; i ++){
    //     cout << i << " => ";
    //     for(auto [u, w] : g[i]) cout << u << " ";
    //     cout << endl;
    // }

    cout << min(dist[2 * n], dist[2 * n + 1]) << endl;
    return 0;
} 
