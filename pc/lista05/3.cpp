#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
// const int MAX = 1e5 + 10;

vector<ll> seg;
vector<int> arr;

ll build(int p, int l, int r){
    if(l == r) return seg[p] = (1LL << arr[l]);
    int m = (l + r)/2;
    return seg[p] = build(p << 1, l, m) | build(p << 1 | 1, m + 1, r);
}

ll update(int p, int l, int r, int i, int t){
    if(l > i or r < i) return seg[p];
    if(l == r) return seg[p] = (1LL << t);
    int m = (l + r)/2;
    return seg[p] = update(p << 1, l, m, i, t) | update(p << 1 | 1, m + 1, r, i, t);
}

ll query(int p, int l, int r, int lq, int rq){
    if(lq > r or rq < l) return 0LL;
    if(lq <= l and r <= rq) return seg[p];

    int m = (l + r)/2;
    return query(p << 1, l, m, lq, rq) | query(p << 1 | 1, m+1, r, lq, rq);
}

int main(){ _
    int n, q, tipos; 
    cin >> n >> q >> tipos;
    arr.resize(n);
    seg.resize(4 * n);
    for(auto& el: arr) cin >> el;
    build(1, 0, n-1);
    while(q --){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r; l-- ,r --;
            auto val = query(1, 0, n-1, l, r);
            cout << __builtin_popcountll(val) << endl;
        }else {
            int c, ty; cin >> c >> ty; c--;
            update(1, 0, n-1, c, ty);
        }
    }


    return 0;
} 
