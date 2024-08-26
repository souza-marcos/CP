#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
vector<vector<pair<int, int>>> g(MAX); // arestas com peso (w, v)
vector<int> dist(MAX, INF);

void dj(int s){
    priority_queue<pair<int, int>> pq; pq.push({0, s}); // 
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop(); // Aresta não visitada incidente em u
        d = -d;
        if(d >= dist[u]) continue; // Aresta "inutil"
        dist[u] = d;
        for(auto ed : g[u]){
            int w = d + ed.first;
            if(dist[ed.second] > w) pq.push({-w, ed.second});
        }
    }
}


int main(){ _
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w; a--, b--;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    dj(0);

    for(int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
} 
