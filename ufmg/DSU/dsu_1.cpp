#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<tuple<int, int, int>> info; // min, max, num_el
vector<int> id, sz;

int find(int x){
    return id[x] = (id[x] == x? x: find(id[x]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;

    if(sz[a] > sz[b]) swap(a, b);
    id[a] = b;
    auto [min_a, max_a, num_el_a] = info[a];
    auto& [min_b, max_b, num_el_b] = info[b];
    min_b = min(min_a, min_b);
    max_b = max(max_a, max_b);
    num_el_b += num_el_a;

    sz[b] += sz[a];
}

int main(){ _
    int n, m; cin >> n >> m;
    id.resize(n);
    sz.resize(n, 0);
    info.resize(n);
    for(int i = 0; i < n; i++){
        auto& [min_i, max_i, num_el] = info[i];
        min_i = i; max_i = i; num_el = 1;
    }

    iota(id.begin(), id.end(), 0);
    while (m --)
    {
        string query;
        int u, v;
        cin >> query;
        if(query == "union") {
            cin >> u >> v; u --, v --;
            uni(u, v);
        } 
        else {
            cin >> u; u --;
            int rep = find(u);
            auto [min_s, max_s, num_el] = info[rep];
            cout << min_s + 1 << " " << max_s + 1 << " " << num_el << endl;
        }
    }


    return 0;
} 
