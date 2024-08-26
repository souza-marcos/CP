#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<int> arr;
vector<pair<int, int>> seg; // min, count
int n, m;

// Sum segmented tree
pair<int, int> combine(pair<int, int> f, pair<int, int> s){
    if(f.first == s.first) return {f.first, f.second + s.second};
    if(f > s) swap(f, s);
    return f;
}
void build(int p, int l, int r){
    if(l == r){ seg[p] = {arr[l], 1}; return; }
    
    int m = (l + r)/2;
    build(2 * p, l, m), build(2 * p + 1, m + 1, r);

    seg[p] = combine(seg[p << 1], seg[p << 1 | 1]);
}

// Update a leaf
pair<int, int> update(int p, int l, int r, int i, int v){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = {v, 1};

    int m = (l + r)/2;
    return seg[p] = combine(update(2 * p, l, m, i, v), update(2 * p + 1, m + 1, r, i, v));
}

pair<int, int> query(int p, int l, int r, int lq, int rq){
    if(rq < l or r < lq) return {INF, 1};
    if(lq <= l and r <= rq) return seg[p];

    int m = (l + r)/2;
    return combine(query(2 * p, l, m, lq, rq), query(2 * p + 1, m + 1, r, lq, rq));
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
            auto [minval, cnt] = query(1, 0, n-1, l, r);
            cout << minval << " " << cnt << endl;
        }
    }

    return 0;
} 
