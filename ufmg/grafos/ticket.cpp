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
    vector<vector<pair<ll, int>>> g(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        ll cost; cin >> cost; cost <<= 1;
        g[a].push_back({cost, b});
        g[b].push_back({cost, a});
    }

    vector<ll> val(n); for(ll& el:val) cin >> el;
    
    for(int i = 0; i < n; i++){

        priority_queue<pair<ll,int>> pq;
        for(int j = 0; j < n; j ++) pq.push({-val[j], j});
        vector<bool> vis(n, false);
        while (!pq.empty())
        {
            auto [d, u] = pq.top(); pq.pop();
            d = -d;
            if(vis[u]) continue;
            val[u] = d;
            vis[u] = true;
            for(auto [w, adj] : g[u]){
                w += val[u];
                if(w < val[adj]) pq.push({-w, adj});
            }
        }
    }

    for(ll el: val) cout << el << " ";
    cout << endl;
    
    return 0;
} 
