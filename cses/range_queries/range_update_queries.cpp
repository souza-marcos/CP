#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

// Seg tree with lazy propagation
// No need to be sum seg but I prefer it to practice

const int MAX = 2e5 + 10;
ll seg[4*MAX], lz[4*MAX];
vector<ll> arr;

ll build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l];
    int m = (l + r)/2;
    return build(p << 1, l, m) + build(p << 1 | 1, m + 1, r);
}

void prop(int p, int l, int r){
    seg[p] += lz[p] * (r - l + 1); 
    if(l != r)
        lz[p << 1] += lz[p], lz[p << 1 | 1] += lz[p];
    lz[p] = 0;
}

ll query(int p, int l, int r, int k){
    prop(p, l, r);
    if(l > k or r < k) return 0;
    if(l == r) return seg[p];
    int m = (l + r)/2;
    return query(p << 1, l, m, k) + query(p << 1 | 1, m + 1, r, k);
}

ll update(int p, int l, int r, int lu, int ru, ll delta){
    prop(p, l, r);
    if(ru < l or r < lu) return seg[p];
    if(l >= lu and r <= ru){
        lz[p] += delta;
        prop(p, l, r);
        return seg[p];
    }
    int m = (l + r)/2;
    return seg[p] = update(p << 1, l, m, lu, ru, delta) + update(p << 1 | 1, m + 1, r, lu, ru, delta);
}


int main(){ _ 
    int n, q; cin >> n >> q;
    arr.resize(n);
    for(auto& el: arr) cin >> el;
    build(1, 0, n-1);

    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll a, b, val; cin >> a >> b >> val;
            a --, b--;
            update(1, 0, n-1, a, b, val); 
        } else {
            int k; cin >> k; k--;
            cout << query(1, 0, n-1, k) << endl;
        }
    }

    return 0;
} 
