#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n, s1, s2; cin >> n >> s1 >> s2; s1--, s2--;
    vector<vector<int>> g(n), h(n);
    vector<vector<int>> out(n * n);
    int m1; cin >> m1;
    for(int i = 0; i < m1; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int m2; cin >> m2;
    for(int i = 0; i < m2; i++){
        int a, b; cin >> a >> b; a--, b--;
        h[a].emplace_back(b);
        h[b].emplace_back(a);
    }

    auto get_index = [&](int i, int j) { return i * n + j; };

    queue<pair<int, int>> q; q.emplace(s1, s2);
    vector<bool> vis(n * n, false);
    while(!q.empty()){
        auto [v1, v2] = q.front(); q.pop();
        int idx = get_index(v1, v2);
        if(vis[idx]) continue;
        vis[idx] = true;

        for(int u1 : g[v1]){
            for(int u2 : h[v2]){
                int u_idx = get_index(u1, u2);
                out[idx].emplace_back(u_idx);
                out[u_idx].emplace_back(idx);
                if(!vis[u_idx]) q.emplace(u1, u2);
            }
        }
    }

    vector<bool> is_endpoint(n * n, false);
    for(int i = 0; i < n; i++){
        int v = get_index(i, i);
        for(int j = i + 1; j < n; j++){
            int u = get_index(j, j);
            if(find(out[v].begin(), out[v].end(), u) != out[v].end()){
                is_endpoint[v] = is_endpoint[u] = true;
            }
        }
    }

    bool has_endpoint = false;
    for(int i = 0; i < n * n; i++){
        if(is_endpoint[i]){
            has_endpoint = true;
            break;
        }
    }
    if(!has_endpoint){
        cout << -1 << '\n';
        return;
    }

    vector<int> dist(n * n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, get_index(s1, s2));
    while(!pq.empty()){
        auto [w, v] = pq.top(); pq.pop();
        if(w >= dist[v]) continue;
        dist[v] = w;

        for(int u : out[v]){
            auto [x, y] = make_pair(u / n, u % n);
            int to_w = w + abs(x - y);
            if(dist[u] > to_w) pq.emplace(to_w, u);
        }
    }

    int minv = INF;
    for(int i = 0; i < n * n; i++){
        if(is_endpoint[i]) minv = min(minv, dist[i]);
    }
    cout << minv << '\n';
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
}