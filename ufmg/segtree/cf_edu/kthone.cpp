#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const int MAX = 1e5 + 10;

bool arr[MAX];
int seg[4 * MAX];

int build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l];

    int m = (l + r)/2;
    return seg[p] = build(p << 1, l, m) + build(p << 1 | 1, m + 1, r);
}

int update(int p, int l, int r, int i){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = !seg[p];

    int m = (l + r)/2;
    return seg[p] = update(p << 1, l, m, i) + update(p << 1 | 1, m + 1, r, i);
}

int query(int p, int l, int r, int k){
    if(l == r) return l;
    int m = (l + r) /2; 
    // cout << "P node: " << p << " => [" << l << ", " << r << "], " << seg[p << 1] << " - " << seg[p << 1 | 1] << endl;
    
    if(seg[p << 1] >= k) return query(p << 1, l, m, k);
    else { 
        return query(p << 1 | 1, m + 1, r, k - seg[p << 1]);
    }
}

int main(){ _
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n -1);
    while(m --){
        int t, v; cin >> t >> v;
        if(t == 1) update(1, 0, n-1, v);
        else cout << query(1, 0, n-1, v + 1) << endl;
    }   

    return 0;
} 
