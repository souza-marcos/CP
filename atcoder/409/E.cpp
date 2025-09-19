#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _
    // Tenho uma arvore, quero processar as folhas e removê-las de modo a 
    // processar primeiro aquelas que possuem menor peso da aresta que ligam no resto da arvore

    int n; cin >> n;
    vector<ll> value_vertice(n); 
    for(auto& el : value_vertice) cin >> el;

    vector<pair<multiset<int>, set<int>>> g(n);
    for(int i = 0; i < n-1; i ++){
        int a, b, w; cin >> a >> b >> w;
        a --, b--;
        g[a].first.insert(w); 
        g[a].second.insert(b);
        g[b].first.insert(w);
        g[b].second.insert(a);
    }
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > pq; 
    for(int i = 0; i < n; i ++){
        if(sz(g[i].first) == 1) pq.push({*g[i].first.begin(), i});
    }

    ll res = 0;
    int cnt = 0;
    while(sz(pq)){
        auto [weight, v] = pq.top();
        pq.pop();
        int u = *g[v].second.begin();
        value_vertice[u] += value_vertice[v];
        
        g[u].first.erase(g[u].first.find(weight));
        g[u].second.erase(v);
        if(sz(g[u].first) == 1) pq.push({*g[u].first.begin(), u});

        res += weight * abs(value_vertice[v]);
        cnt += 1;
        if(cnt == n-1) break;
    }
    cout << res << endl;

    return 0;
} 
