#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acosl(-1);

#define sz(x) (int)x.size()

int main(){ _
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> g(n); // cost, a

    for(int i = 0; i < m; i ++){
        int a, b, cost; cin >> a >> b >> cost;
        a --, b --;
        g[a].push_back({cost, b});
        g[b].push_back({cost, a});
    }

    priority_queue<tuple<int, int, int>> pq; // -cost, v, parent;
    pq.push({0, 0, 0}); // peso, source

    vector<int> dist(n, INF), par(n, -1);
    while(!pq.empty()){
        auto [d, v, par_u] = pq.top(); pq.pop();
        d = -d;
        if(d >= dist[v]) continue;
        dist[v] = d;
        par[v] = par_u;
        for(auto [w, u] : g[v]){
            w += d;
            if(dist[u] >  w) pq.push({-w, u, v});
        }
    }

    for(auto el: dist) cout << el << " ";
    cout << endl;

    for(auto el: par) cout << el + 1 << " ";
    cout << endl;

    return 0;
} 
