#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 10;
vector<vector<pair<int, int>>> g(MAX); // arestas com peso (w, v)

void dj(int s, vector<int> &dist){
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
    int n, m, x; cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w; a--, b--;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    vector<int> amigos(x);
    for(auto &el : amigos){ cin >> el; el --;}

    vector<int> dist1(MAX, INF), dist2(MAX, INF);
    dj(0, dist1);
    dj(n-1, dist2);


    int min_dist = INF;
    for(auto el: amigos) min_dist = min(min_dist, dist1[el] + dist2[el]);
    
    cout << min_dist << endl;
    return 0;
} 
