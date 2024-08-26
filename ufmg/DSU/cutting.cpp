#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<tuple<int, int, int>> ops; // op, vert a, vert b

vector<int> id, sz;
int find(int x){
    return id[x] = (x == id[x]? x: find(id[x]));
}

void uni(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return; // Never happens here
    if(sz[u] > sz[v]) swap(u, v); // u always keep the less
    id[u] = v;

    sz[v] += sz[u];
}

int main(){ _
    int n, m, k; cin >> n >> m >> k;
    
    sz.resize(n, 1);
    id.resize(n);
    iota(id.begin(), id.end(), 0);
    
    for(int i = 0; i < m; i ++) {
        int u, v; cin >> u >> v; u --, v--;
    }

    string q; int u, v;
    ops.resize(k);
    for(int i = 0; i < k; i++){
        cin >> q >> u >> v; u--, v--;
        ops[i] = make_tuple((q == "ask"), u, v);
    }

    stack<bool> res;
    for(int i = k -1; i >= 0; i--){
        auto [op, u, v] = ops[i];
        if(op) res.push(find(u) == find(v));
        else uni(u, v);
    }
    while(!res.empty()){
        cout << (res.top()?"YES":"NO") << endl;
        res.pop();
    }

    return 0;
} 
