#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _

    int n, m, k; cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> g(n+k);
    for(int i = 0; i < m; i ++){
        ll a, b, c; cin >> a >> b >> c;
        a --, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    //vector<vector<pair<int, ll>>> tele_by_city(n);
    //vector<vector<int>> cities_by_tele(k);


    for(int i = 0; i < n; i ++){
        int t; cin >> t;
        for(int j = 0; j < t; j ++){
            ll tipo, custo; cin >> tipo >> custo; tipo --;
            
            g[i].push_back({n+tipo,custo});
            g[n+tipo].push_back({i,0});
        }
    }

    vector<ll> dist(n+k, LINF);
        
    auto dijkstra = [&](int v) -> ll {
        dist[v] = 0;
        priority_queue<pair<ll, int>> pq;
        pq.emplace(0, v);
    
        while (pq.size()) {
            auto [ndist, u] = pq.top(); pq.pop();
            if(u == n-1) return dist[n-1];
            if (-ndist > dist[u]) continue;
    
            // ruas
            for (auto [idx, w] : g[u]) if (dist[idx] > dist[u] + w) {
                dist[idx] = dist[u] + w;
                pq.emplace(-dist[idx], idx);
            }

            // teleporters
            //for (auto [tipo, custo] : tele_by_city[u]){
            //    for(int to : cities_by_tele[tipo]) if(dist[to] > dist[u] + custo){
            //        dist[to] = dist[u] + custo;
            //        pq.emplace(-dist[to], to);
            //    }
            //}
        }   
        return dist[n-1];
    };   


    cout << dijkstra(0) << endl;

}