#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 2e5 + 10;
vector<ll> arr, prefix;
ll seg[4*MAX], lazy[4*MAX];
int n;

ll build(int p, int l, int r) {
    if(l == r) return seg[p] = prefix[l];
    int m = (l + r)/2;
    return seg[p] = max(build(p << 1, l, m), build(p << 1 | 1, m + 1, r));
}

void prop(int p, int l, int r) {
    if(lazy[p]){
        seg[p] += lazy[p];
        if(l != r) lazy[p << 1] += lazy[p], lazy[p<<1 | 1] += lazy[p];
        lazy[p] = 0;
    }
}

ll query(int p, int l, int r, int lq, int rq){
    prop(p, l, r);
    if(lq <= l and r <= rq) return seg[p];
    if(lq > r or rq < l) return -LINF;
    int m = (l + r)/2;
    return max(query(p << 1, l, m, lq, rq), query(p << 1 | 1, m+1, r, lq, rq));
}

ll update(int p, int l, int r, int lu, int ru, int delta){
    prop(p, l, r);
    if(lu <= l and r <= ru){
        lazy[p] += delta;
        prop(p, l, r);
        return seg[p];
    }
    if(lu > r or ru < l) return seg[p];
    int m = (l + r)/2;
    return seg[p] = max(update(p << 1, l, m, lu, ru, delta), update(p << 1 | 1, m + 1, r, lu, ru, delta));
}

int main(){ _
    int n, q; cin >> n >> q;
    arr.resize(n);
    prefix.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        prefix[i] = arr[i] + (i > 0 ? prefix[i-1] : 0);
    }    

    build(1, 0, n-1);
    
    
    while(q --) {
        int t; cin >> t;
        if(t == 1){
            ll k, u; cin >> k >> u; k--;
            int delta = u - arr[k];
            arr[k] = u;
            update(1, 0, n-1, k, n-1, delta);
        }else {
            int a, b; cin >> a >> b;
            a--, b--;
            ll res = query(1, 0, n-1, a, b) - (a > 0 ? query(1, 0, n-1, a-1,a-1) : 0);
            cout << max(0LL, res) << endl; // não somar nada
        }   
    }
    
    
    return 0;
} 
