#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    map<pair<int, int>, int> order_edges;
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b; a--, b--;
        if(a > b) swap(a, b);
        order_edges[{a, b}] = i;
        g[a].push_back(b),
        g[b].push_back(a);
    } 

    vector<int> minv(n, INF);
    minv[0] = 1;
    auto dfs = [&](auto&& dfs, int v, int p) -> void {
        for(auto u : g[v]) if(u != p){
            int last = order_edges[{min(p, v), max(p, v)}];
            int cur = order_edges[{min(v, u), max(v, u)}];
            minv[u] = minv[v] + (cur < last);
            dfs(dfs, u, v);
        }
    };
    dfs(dfs, 0, -1);

    cout << *max_element(minv.begin(), minv.end()) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
