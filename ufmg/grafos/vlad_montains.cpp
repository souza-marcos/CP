#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
vector<int> id, szo;
vector<tuple<int, int, int>> edges;

int find(int a){
    return id[a] = (id[a] == a? a: find(id[a]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(szo[a] < szo[b]) swap(a, b);

    id[b] = a;
    szo[a] += szo[b];
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> heights(n); for(auto& el: heights) cin >> el;
    edges.resize(m);

    id.resize(n), szo.assign(n, 1);
    iota(id.begin(), id.end(), 0);

    for(auto& [cost, a, b] : edges){
        cin >> a >> b; a --, b--;
        cost = max(heights[a], heights[b]);
    }

    struct Query { int a, b, e; };
    int q; cin >> q;
    vector<tuple<int, Query, int>> queries(q);
    int i = 0;
    for(auto& [cost, cur, idx] : queries){
        auto& [a, b, e] = cur;
        cin >> a >> b >> e; a--, b--;
        cost = heights[a] + e;
        idx = i++;
    }

    sort(queries.begin(), queries.end(), [](auto& left, auto& right){
        return get<0>(left) < get<0>(right);
    });

    sort(edges.begin(), edges.end());
    
    vector<bool> res(q, false);

    i = 0;
    for(auto [z, cur, idx] : queries){
        auto [a, b, e] = cur;

        while(i < sz(edges) and get<0>(edges[i]) <= heights[a] + e)
            uni(get<1>(edges[i]), get<2>(edges[i])), i ++;

        res[idx] = (find(a) == find(b));
    }
    for(auto ok: res)
        cout << (ok ? "YES\n" : "NO\n");
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
