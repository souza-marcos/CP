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
    vector<vector<pair<int, int>>> g(n); // neig - cost

    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
    
        u --, v --;
        g[v].push_back({w, u});
        g[u].push_back({w, v});
    }

    // Prim
    vector<int> vis(n, false);
    priority_queue<pair<int, int>> pq;
    vis[0] = true;
    for(auto [u, w]: g[0]) pq.push({-w, u}); 

    while(pq.empty()){
        auto [w, v] = pq.top(); pq.pop();
        w = -w;

        if(vis[v]) continue;

        

    }

    return 0;
} 
