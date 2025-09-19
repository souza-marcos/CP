#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 2e5 + 5;
struct segtree {
    vector<ll> seg;
    vector<ll> arr;

    ll build(int p, int l, int r){
        if(l == r) return seg[p] = arr[l];
        int m = (l + r)/2;
        return seg[p] = min(build(p << 1, l, m), build(p << 1 | 1, m + 1, r));
    }

    ll query(int p, int l, int r, int lq, int rq){
        if(lq <= l and r <= rq) return seg[p];
        if(l > rq or r < lq) return LINF;
        int m = (l + r)/2;
        return min(query(p << 1, l, m, lq, rq), query(p << 1 | 1, m + 1, r, lq, rq));
    }

    ll update(int p, int l, int r, int k, int x){
        if(l > k or r < k) return seg[p];
        if(l == r) return seg[p] = x;
        int m = (l + r)/2;
        return seg[p] = min(update(p << 1, l, m, k, x), update(p << 1 | 1, m + 1, r, k, x));
    }
};

int main(){ _
    
    int n, q; cin >> n >> q;
    vector<ll> arr(n); 
    for(ll& el : arr) cin >> el;

    segtree left, right;
    left.arr.resize(n), right.arr.resize(n);
    left.seg.resize(4*n), right.seg.resize(4*n);
    
    for(int i = 0; i < n; i ++)
        right.arr[i] = arr[i] + i;

    for(int i = n-1, j = 0; i >= 0; i--, j ++)
        left.arr[i] += arr[i] + j;

    left.build(1, 0, n-1), right.build(1, 0, n-1);

    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll k, x; cin >> k >> x;
            k --;
            left.arr[k] = left.arr[k] - arr[k] + x;
            right.arr[k] = right.arr[k] - arr[k] + x;
            arr[k] = x;

            left.update(1, 0, n-1, k, left.arr[k]);
            right.update(1, 0, n-1, k, right.arr[k]);
        } else {
            int k; cin >> k; k --;
            ll minleft = left.query(1, 0, n-1, 0, k-1) - (left.arr[k] - arr[k]);
            ll minright = right.query(1, 0, n-1, k+1, n-1) - (right.arr[k] - arr[k]);
            cout << min({minleft, minright, arr[k]}) << endl; 
        }
    }

    


    return 0;
} 
