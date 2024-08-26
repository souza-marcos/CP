#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<int> dist(n, INF);
    for(int i =0; i < m; i++){
        int a, b, p; cin >> a >> b >> p; a--, b--;
        g[a].push_back({p, b});
        g[b].push_back({p, a});
    }

    int s; cin >> s; s--;

    priority_queue<pair<int, int>> pq; pq.push({0, s});
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[v] <= d) continue;
        dist[v] = d;
        for(auto [w, u]: g[v]){
            int dnew = d + w;
            if(dnew < dist[u])pq.push({-dnew, u});
        }
    }

    int minp = INF, maxp = -1;
    for(int i = 0; i < n; i++){
        if(dist[i] == 0) continue;
        minp = min(minp, dist[i]);
        maxp = max(maxp, dist[i]);
    }

    cout << maxp - minp << endl;

    return 0;
}