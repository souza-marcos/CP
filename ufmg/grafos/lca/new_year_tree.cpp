#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

typedef bitset<60> arr;
const int MAX = 4e5 + 10;
vector<int> order, lazy(4*MAX), color;
vector<arr> seg(4*MAX);

// Quero propagar a cor para os de baixo 

arr combine(arr left, arr right){
    return left | right;
}

void prop(int p, int l, int r) {
    if(lazy[p]) {
        seg[p] = arr();
        seg[p][lazy[p] - 1] = 1;
        if(l != r){
            lazy[p << 1] = lazy[p << 1 | 1] = lazy[p];
        }
    }
    lazy[p] = 0;
}

void build(int p, int l, int r){
    if(l == r) {
        seg[p][color[order[l]]-1] = 1;
        return;
    }
    int m = (l + r)/2;
    build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
    seg[p] = combine(seg[p << 1], seg[p << 1 | 1]);
}

arr query(int p, int l, int r, int lq, int rq){
    prop(p, l, r);
    if(l >= lq and r <= rq) return seg[p];
    if(rq < l or lq > r) return arr();
    int m = (l + r)/2;
    return combine(query(p << 1, l, m, lq, rq), query(p << 1 | 1, m + 1, r, lq, rq));
}

arr update(int p, int l, int r, int lu, int ru, int x) {
    prop(p, l, r);
    if(l >= lu and r <= ru){
        lazy[p] = x;
        prop(p, l, r);
        return seg[p];
    }
    if(r < lu or l > ru) return seg[p];
    int m = (l + r)/2;
    return seg[p] = combine(update(p << 1, l, m, lu, ru, x), update(p << 1 | 1, m + 1, r, lu, ru, x));
}

void print(int p, int l, int r){
    prop(p, l, r);
    if(l == r){
        cout << l << ": ";
        for(int i = 0; i < 60; i ++) cout << seg[p][i] << " ";
        cout << endl;
        return;
    }

    int m = (l + r)/2;
    print(p << 1, l, m), print(p << 1 | 1, m + 1, r);
}

int main(){ _

    int n, q; cin >> n >> q;
    color.resize(n); for(auto& el : color) cin >> el;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b),
        g[b].push_back(a);
    }
    vector<int> tin(n), tout(n);
    int timer = -1;
    auto dfs = [&](auto&& dfs, int v, int p) -> void {
        tin[v] = ++timer;
        order.push_back(v);
        for(auto u : g[v]) if(u != p){
            dfs(dfs, u, v);
        }
        tout[v]=timer;
    };

    dfs(dfs, 0, -1);
    build(1, 0, n-1);

    while(q --){
        int t; cin >> t;
        if(t == 1){
            int v, c; cin >> v >> c; v--;
            update(1, 0, n-1, tin[v], tout[v], c);
        } else {
            int v; cin >> v; v--;
            arr res = query(1, 0, n-1, tin[v], tout[v]);
            int cnt = 0;

            for(int i = 0 ; i < 60; i ++) cnt += res[i];
            cout << cnt << endl;
        }
    }


    return 0;
} 
