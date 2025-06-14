#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    for(int i = 0; i < m; i ++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
    }

    priority_queue<pair<ll, int>> pq;
    pq.push({-0, 0});
    vector<ll> dist(n, LINF);
    dist[0] = 0;

    while(sz(pq)){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if(d > dist[v]) continue;
        for(auto [u, w]: g[v]){
            if(d + w < dist[u]){
                dist[u] = d + w;
                pq.push({-dist[u], u});
            }
        }
    }
    for(auto el : dist) cout << el << " ";
    cout << endl;
}
