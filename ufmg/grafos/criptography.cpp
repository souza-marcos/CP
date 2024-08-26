#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define sz(a) (int)(a).size()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int caracWeight = 33;

int main(){ _
    string s, t; cin >> s >> t;
    int n; cin >> n;
    set<int> vertices;
    vector<vector<pair<ll, ll>>> g(127);

    for(int i = 0; i < n; i++){
        char a, b; cin >> a >> b;
        int cost; cin >> cost;
        int x = a - caracWeight;
        int y = b - caracWeight;

        vertices.insert(x), vertices.insert(y);
        g[x].push_back({cost, y});
        // g[y].push_back({cost, x});
    }

    int dist[127];
    ll total_cost = 0;
    for(int i = 0; i < sz(s); i++){
        if(s[i] == t[i]) continue;
        if(vertices.count(s[i]-caracWeight) == 0 or vertices.count(t[i]-caracWeight) == 0) {
            cout << -1 << endl; return 0;
        }

        memset(dist, INF, sizeof dist);
        priority_queue<pair<int, int>> pq; pq.push({0, s[i] - caracWeight});

        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            d = -d;
            if(d >= dist[u]) continue;
            dist[u] = d;

            if(u == (t[i]-caracWeight)) break;

            for(auto [w, a]: g[u]){
                w += dist[u];
                if(dist[a] > w) pq.push({-w, a});
            }
        }

        if(dist[t[i]-caracWeight] == INF){ cout << -1 << endl; return 0; }
        total_cost += dist[t[i]-caracWeight];
    }
    cout << total_cost << endl;

    return 0;
} 
