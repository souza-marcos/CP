#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    vector<tuple<int, int, ll>> edges;
    for(int i = 0; i < m; i ++){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edges.push_back({a, b, c});
    }
    
    auto dijkstra = [&](int in) -> vector<ll> {
        // heap dist (min max weight in the path) / vertice
        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<>> pq;

        pq.push({0, in});
        vector<ll> dist(n, LINF);
        dist[in]=0;
        while(sz(pq)){
            auto [d, v] = pq.top(); pq.pop();
            if(d > dist[v]) continue;
            for(auto [u, w] : g[v]) {
                ll dnew = max(w, d);
                if(dist[u] > dnew){
                    dist[u] = dnew;
                    pq.emplace(dnew, u);
                }
            }
        }
        return dist;
    };

    vector<ll> dist_begin = dijkstra(0),
               dist_end   = dijkstra(n-1);    

    
    ll mindist = LINF;
    for(auto [a, b, w] : edges){
        mindist = min({mindist,
            max({dist_begin[a], w, dist_end[b]}) + w,
        });
    }
    cout << mindist << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
