#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, q;
vector<vector<pair<int, int>>> g;
vector<int> dist;

void dj(vector<int> &s){
    priority_queue<pair<int, int>> pq;
    for(auto el: s) pq.push({0, el});

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        d = -d;
        if(dist[u] <= d) continue;
        dist[u] = d;
        for(pair<int, int> ed: g[u]){
            int dnew = d + ed.first;
            if(dist[ed.second] > dnew) pq.push({-dnew, ed.second});
        }
    }
}

void solve(){
    g.assign(n + 10, vector<pair<int, int>>()), dist.assign(n, INF); 
    for(int i =0; i < m; i++){
        int a, b, w; cin >> a >> b >> w; a--, b--;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    vector<int> h(q); 
    for(auto &el: h) {cin >> el; el --;}

    dj(h); 

    int maxlen = -1;
    for(int i = 0; i < n; i ++) maxlen = max(maxlen, dist[i]);

    cout << maxlen << endl;
}

int main(){ _
    while(cin >> n >> m >> q) solve();
    return 0;
} 
