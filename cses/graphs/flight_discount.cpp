#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(2*n);

    auto get_down = [n](int a) -> int{
        return a + n;
    };

    for(int i = 0; i < m; i ++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
        g[a].push_back({get_down(b), c/2});
        g[get_down(a)].push_back({get_down(b), c});
    }

    vector<ll> dist(2*n, LINF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq; 
    pq.push({0, 0});
    while(sz(pq)){
        auto [d, v] = pq.top(); pq.pop();
        if(dist[v] < d) continue;
        dist[v] = d;
        for(auto [u, w] : g[v]){
            if(dist[v] + w < dist[u]){
                pq.push({dist[v] + w, u});
                dist[u] = dist[v]+ w;
            } 
        }
    }

    cout << dist[get_down(n-1)] << endl;
}