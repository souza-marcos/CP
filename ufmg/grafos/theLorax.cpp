// https://codeforces.com/gym/102694/problem/F
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

const int MAX = 1e5 + 10;
ll seg[4 * MAX];

ll build(int p, int l, int r){
    if(l == r) return seg[p] = 0;
    int m = (l + r)/2;
    return seg[p] = build(p << 1, l, m) + build(p << 1 | 1, m + 1, r);
}

ll query(int p, int l, int r, int lq, int rq){
    if(lq > r or rq < l) return 0;
    if(lq <= l and rq >= r) return seg[p];
    int m = (l + r)/2;
    return query(p << 1, l, m, lq, rq) + query(p << 1 | 1, m + 1, r, lq, rq);
}

ll update(int p, int l, int r, int i, int x){
    if(l > i or r < i) return seg[p];
    if(l == r) return seg[p] += x;
    int m = (l + r)/2;
    return seg[p] = update(p << 1, l, m, i, x) + update(p << 1 | 1, m + 1, r, i, x);
}

// void print(int p, int l, int r){
//     cout << "["<< l << ", " << r << "] => " << seg[p] << endl;
//     if(l == r) return; 
//     int m = (l+r)/2;
//     print(p << 1, l, m);
//     print(p << 1 | 1, m + 1, r);
// }


int n, q, timer = 0;
vector<vector<int>> g;
vector<int> pre, pos, parent;

void dfs(int p, int v){
    parent[v] = p;
    pre[v] = timer;
    for(int u: g[v]) if(u != p) ++timer, dfs(v, u);
    pos[v] = timer;
}


void solve(){
    cin >> n >> q;
    g.assign(n, {});
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b), g[b].push_back(a);    
    }


    timer = 0;
    pre.resize(n), pos.resize(n), parent.resize(n);
    dfs(-1, 0);
    build(1, 0, n-1);

    while(q--){
        int a, b, x; cin >> a >> b >> x;
        a --, b--;
        if(x) {
            update(1, 0, n-1, pre[a], x);
            update(1, 0, n-1, pre[b], -x);
        } else {
            if(parent[a] == b) swap(a, b);
            ll val = query(1, 0, n-1, pre[b], pos[b]);
            cout << abs(val) << endl;
        }
    }
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
