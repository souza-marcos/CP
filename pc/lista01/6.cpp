#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int n, m, k;
double p;

vector<vector<int>> g;
vector<int> dist, sold;

void solve(){
    g.assign(n, vector<int>()), dist.assign(n, INF), sold.assign(n, 0);
    cin >> k >> p;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b); g[b].push_back(a);
    }

    int a; cin >> a;
    while (a--){
        int s; cin >> s; sold[s - 1] ++;
    }

    int ini, fin; cin >> ini >> fin; ini --, fin --;

    priority_queue<pair<int, int>> pq; pq.push({-sold[ini], ini});
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[v] <= d) continue;
        dist[v] = d;
        if(v == fin) break;// N sei se funciona 
        for(int u: g[v]){
            int dnew = sold[u] + d;
            if(dist[u] > dnew) pq.push({-dnew, u}); 
        }
    }
    if(dist[fin] > k) cout << "0.000\n";
    else cout << fixed << setprecision(3) << pow(p, dist[fin]) << endl;
}

int main(){_

    while(cin >> n >> m) solve();

    return 0;
}