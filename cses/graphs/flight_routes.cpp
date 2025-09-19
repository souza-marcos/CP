#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int32_t main(){ _ 
    // Find the k-shortest paths 

    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> g(n);
    for(int i = 0; i < m; i ++){
        ll a, b, c; cin >> a >> b >> c;
        a --, b--;
        g[a].emplace_back(b, c);
    }

    priority_queue<ll> dist[n];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    dist[0].push(0);
    pq.push({0, 0});

    while(sz(pq)){
        auto [d, v] = pq.top(); pq.pop();
        if(d > dist[v].top()) continue;
        for(auto [u, w] : g[v]){
            ll newd = d + w;
            if(sz(dist[u]) < k){
                dist[u].push(newd);
                pq.push({newd, u});
            }
            else if(newd < dist[u].top()){
                dist[u].pop();
                dist[u].push(newd);
                pq.push({newd, u});
            }
        }
    }

    vector<ll> res;
    while(sz(dist[n-1])){
        res.push_back(dist[n-1].top());
        dist[n-1].pop();
    }
    reverse(res.begin(), res.end());
    for(auto el : res) cout << el << " ";
    cout << endl;
}