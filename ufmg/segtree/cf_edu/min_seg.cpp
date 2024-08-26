#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<int> arr;
vector<int> seg;
int n, m;

// Sum segmented tree

int build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l];
    int m = (l + r)/2;
    return seg[p] = min(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
}

// Update a leaf
int update(int p, int l, int r, int i, int v){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = v;

    int m = (l + r)/2;
    return seg[p] = min(update(2 * p, l, m, i, v), update(2 * p + 1, m + 1, r, i, v));
}

int query(int p, int l, int r, int lq, int rq){
    if(rq < l or r < lq) return INF;
    if(lq <= l and r <= rq) return seg[p];

    int m = (l + r)/2;
    return min(query(2 * p, l, m, lq, rq), query(2 * p + 1, m + 1, r, lq, rq));
}

int main(){ _
    cin >> n >> m;
    arr.resize(n), seg.resize(4 * n);
    
    for(auto &el : arr) cin >> el;

    build(1, 0, n-1);
    while(m --){
        int t; cin >> t;
        if(t == 1){
            int i, v; cin >> i >> v;
            update(1, 0, n-1, i, v);
        }
        else{
            int l, r; cin >> l >> r; r--;
            cout << query(1, 0, n-1, l, r) << endl;
        }
    }

    return 0;
} 
