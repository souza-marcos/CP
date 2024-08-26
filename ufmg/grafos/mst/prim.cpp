#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, cost; cin >> a >> b >> cost;
        a --, b--;
        g[a].push_back({cost, b});
        g[b].push_back({cost, a});
    }

    vector<bool> vis(n, false);
    vis[0] = true; // Source

    priority_queue<pair<int, int>> pq;
    for(auto el: g[0]) pq.push({-el.first, el.second});

    ll total_cost = 0;
    while(!pq.empty()){
        auto [w, u] = pq.top(); pq.pop();
        w = -w;
        if(vis[u]) continue;
        vis[u] = true;
        total_cost += w; // Add edge to answer

        for(auto [w, v]: g[u]){
            if(vis[v]) continue;
            pq.push({-w, v});
        }
    }
    cout << total_cost << endl;

    return 0;
} 
