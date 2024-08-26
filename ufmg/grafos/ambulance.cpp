#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, q;

vector<vector<pair<int, int>>> g(1005); // Grafo com pesos

vector<int> dijkstra(vector<int> &h){

    priority_queue<pair<int, int>> pq;
    for(int amb: h){
        pq.push({-0, amb - 1});
    }
    vector<int> dist(n, INF);

    while(!pq.empty()){
        auto [w, u] = pq.top(); w = -w;

        pq.pop();

        if(dist[u] > w){
            
            dist[u] = w;
            for(auto [v, n_w]: g[u]){
                if(dist[v] > w + n_w){
                    pq.push({-(w + n_w), v});
                }
            }

        }
    }
    return dist;

}

void solve(){

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        a --, b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});

    }
    vector<int> hosp(q);
    for(int& el: hosp) cin >> el;

    vector<int> dist = dijkstra(hosp);

    int ans = -1;
    for(int x: dist){
        ans = max(ans, x);
    }
    cout << ans << endl;

}

int main(){ _

    while(cin >> n >> m >> q)
        solve();

    return 0;
} 
