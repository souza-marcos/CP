// https://codeforces.com/gym/102694/problem/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()
int n, timer = 0;
vector<vector<int>> g;
vector<int> pre, pos;
// Euler Tour + Seg Tree.

void dfs(int p, int v){
    pre[v] = timer;
    for(int u: g[v]) if(u != p) ++timer, dfs(v, u);
    pos[v] = timer;
}

const int MAX = 3e5 + 10;
double seg[4 * MAX];

double update(int p, int l, int r, int i, double val){
    if(l > i or r < i) return seg[p];
    if(l == r) return seg[p] = val;
    int m = (l + r)>>1;
    return seg[p] = update(p << 1, l, m, i, val) + update(p << 1 | 1, m + 1, r, i, val);
}

double query(int p, int l, int r, int lq, int rq){
    if(l > rq or r < lq) return 0;
    if(l >= lq and r <= rq) return seg[p];
    int m = (l + r)>>1;
    return query(p << 1, l, m, lq, rq) + query(p << 1 | 1, m + 1, r, lq, rq);
}

vector<pair<int, double>> v; 
void print(int p, int l, int r){
    if(l == r) return v.push_back({l, seg[p]});
    int m = (l + r)/2;
    print(p << 1, l, m), print(p << 1 | 1, m + 1, r);
}

int main(){_
    cout << fixed << setprecision(10);
    cin >> n;
    g.resize(n), pre.resize(n), pos.resize(n);
    for(int i = 1; i < n; i ++){
        int v, u; cin >> v >> u; v --, u --;
        g[v].push_back(u), g[u].push_back(v);
    }

    dfs(-1, 0);

    // auto db = [&](){
    //     print(1, 0, n-1);
    //     sort(v.begin(), v.end());
    //     for(auto [p, el] : v) cout << el << " ";
    //     cout << endl;
    // };
    // db();

    int q; cin >> q;
    while(q --){
        int t; cin >> t;
        int x, y; cin >> x >> y;

        if(t == 1){
            x--;
            update(1, 0, n-1, pre[x], log((double)y));
            // db();
        } else {
            x--, y--;
            double val1 = query(1, 0, n-1, pre[x], pos[x]);
            double val2 = query(1, 0, n-1, pre[y], pos[y]); 
            double res = val1 - val2;
            if(res >= log(1e9)) cout << 1'000'000'000 << endl;
            else cout << max(exp(res), 1e-9) << endl;
        }
    
    }
    // db();
    return 0;
}