#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, m; cin >> n >> m;
    vector<tuple<ll, int, int>> edges(m);

    for(auto& [cost, a, b] : edges){
        cin >> a >> b >> cost;
        a --, b--;
    }

    sort(edges.begin(), edges.end());
    vector<int> id(n), szo(n, 1);
    iota(id.begin(), id.end(), 0);

    auto find = [&](auto&& find, int a) -> int {
        return id[a] = (id[a] == a? a : find(find, id[a])); 
    };

    auto uni = [&](int a, int b) -> void {
        a = find(find, a), b = find(find, b);
        if(a == b) return;
        if(szo[a] < szo[b]) swap(a, b);
        id[b] = a;
        szo[a] += szo[b];
    };


    vector<vector<pair<ll, int>>> g(n);
    for(auto [cost, a, b] : edges){
        if(find(find, a) == find(find, b)) continue;
        g[a].push_back({cost, b}), g[b].push_back({cost, a});
        uni(a, b);
    }

    ll total = 0;
    vector<int> path;
    auto dfs = [&](auto& dfs, int p, int v) -> void{
        path.push_back(v);
        for(auto [w, u]: g[v]) {
            if(u != p) {
                total += w;
                dfs(dfs, v, u);
                path.push_back(v);
                total += w;
            }
        }
    };
    dfs(dfs, -1, 0);

    cout << total << endl;
    cout << sz(path) << endl;
    for(auto el : path) cout << el + 1 << " ";
    cout << endl;

} 
