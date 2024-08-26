#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const int MAX = 1e5 + 10;

int arr[MAX], seg[MAX * 4];

int build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l];
    int m = (l + r)/2;
    return seg[p] = max(build(p << 1, l, m), build(p << 1 | 1, m + 1, r));
}

int update(int p, int l, int r, int i, int v){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = arr[l] = v;

    int m = (l + r)/2;
    return seg[p] = max(update(p << 1, l, m, i, v), update(p << 1 | 1, m + 1, r, i, v));
}

int query(int p, int l, int r, int k){
    if(l == r) return l;
    int m = (l + r)/2;
    if(seg[p << 1] >= k) return query(p << 1, l, m, k);
    return query(p << 1 | 1, m + 1, r, k);
}

int main(){ _
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    while(m --){
        int t; cin >> t;
        if(t == 1){
            int i, v; cin >> i >> v;
            update(1, 0, n-1, i, v);
        }else{
            int x; cin >> x;
            if(seg[1] < x) cout << -1 << endl;
            else cout << query(1, 0, n-1, x) << endl;
        }
    }

    return 0;
} 
