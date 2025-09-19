#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
const int maxn = 2e5 + 10;
int seg[4 * maxn];
vector<int> arr;

int build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l];
    int m = (l + r)/2;
    return seg[p] = min(build(p << 1, l, m), build(p << 1 | 1, m + 1, r));
}

int query(int p, int l, int r, int lq, int rq){
    if(r < lq or rq < l) return INF;
    if(lq <= l and r <= rq) return seg[p];
    int m = (l + r)/2;
    return min(query(p << 1, l, m, lq, rq), query(p << 1 | 1 , m + 1, r, lq, rq));
}

int update(int p, int l, int r, int k, int x){
    if(l > k or r < k) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l + r)/2;
    return seg[p] = min(update(p << 1, l, m, k, x), update(p << 1 | 1, m + 1, r, k, x));
}

int main(){ _

    int n, q; cin >> n >> q;
    arr.resize(n);
    for(auto &el : arr) cin >> el;

    build(1, 0, n-1);

    while(q --){
        
        int t, a, b; cin >> t >> a >> b;
        if(t == 1){
            a --;
            update(1, 0, n-1, a, b);
        } else {
            a--, b--;
            cout << query(1, 0, n-1, a, b) << endl;
        }
    }

    return 0;
} 
