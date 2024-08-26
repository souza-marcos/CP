#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

#define tll tuple<ll,ll,ll>

vector<int> arr;
vector<tll> seg;
vector<ll> res;

tll combine(tll l, tll r){
    auto [pref1, ent1, suf1] = l;
    auto [pref2, ent2, suf2] = r;
    return {
        max(pref1, ent1 + pref2),
        ent1 + ent2,
        max(suf2, suf1 + ent2)
    };
}

void build(int p, int l, int r){
    if(l == r) { 
        seg[p] = {arr[l], arr[l], arr[l]};
        res[p] = max(arr[l], 0);    
        return; 
    }

    int m = (l + r)/2;
    build(p << 1, l, m), build(p << 1 | 1, m + 1, r);
    seg[p] = combine(seg[p << 1], seg[p << 1 | 1]);
    res[p] = max(max(res[p << 1], res[p << 1 | 1]), get<2>(seg[p << 1]) + get<0>(seg[p << 1 | 1]));
}

void update(int p, int l, int r, int i, int v){
    if(i < l or i > r) return;
    if(l == r){
        seg[p] = {v, v, v};
        res[p] = max(0, v);
        return;
    }

    int m = (l + r)/2;
    update(p << 1, l, m, i, v), update(p << 1 | 1, m + 1, r, i, v);
    seg[p] = combine(seg[p << 1], seg[p << 1 | 1]);
    res[p] = max(max(res[p << 1], res[p << 1 | 1]), get<2>(seg[p << 1]) + get<0>(seg[p << 1 | 1]));
}   

int main(){ _
    int n, m; cin >> n >> m;
    arr.resize(n), seg.resize(4 * n), res.resize(4 * n);

    for(auto& el : arr) cin >> el;
    build(1, 0, n-1);

    cout << res[1] << endl;
    while(m --){
        int i, v; cin >> i >> v;
        update(1, 0, n-1, i, v);
        cout << res[1] << endl;
    }

    return 0;
} 
