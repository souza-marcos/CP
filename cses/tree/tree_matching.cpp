#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    int n; cin >> n;
    vector<bool> used(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> edges;
    vector<set<int>> g(n);

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].insert(b), g[b].insert(a);
    }

    for(int i = 0; i < n; i ++){
        edges.push({sz(g[i]), i});
    }

    int cnt = 0;
    while(sz(edges)){
        auto [d, v] = edges.top(); edges.pop();
        if(used[v] or sz(g[v]) == 0) continue; 
        cnt ++;
        auto u = *g[v].begin();
        // cout << v << " " << u << endl;
        used[v] = used[u] = true;
        for(auto w: g[u]) if(w != v) g[w].erase(u), edges.push({sz(g[w]), w});
    }

    cout << cnt << endl;
    return 0;
} 
