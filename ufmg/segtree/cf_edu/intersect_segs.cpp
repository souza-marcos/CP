#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

const int MAX = 2e5 + 10;
int seg[4 * MAX];

int update(int p, int l, int r, int i){
    if(i > r or i < l) return seg[p];
    if(l == r) return seg[p] = !seg[p];

    int m = (l + r)/2;
    return seg[p] = update(p << 1, l, m, i) + update(p << 1 | 1, m + 1, r, i);
}

int query(int p, int l, int r, int lq, int rq){
    if(l > rq or r < lq) return 0;
    if(l >= lq and r <= rq) return seg[p];

    int m = (l + r)/2;
    return query(p << 1, l, m, lq, rq) + query(p << 1 | 1, m + 1, r, lq, rq);
}

int main(){ _
    int n; cin >> n;
    vector<int> v(n, -1), res(n, 0);
    for(int i = 0; i < 2 * n; i++){
        int a; cin >> a; a--;
        if(v[a] != -1){
            res[a] = query(1, 0, n-1, v[a], i);
            update(1, 0, n-1, v[a]);
        } else {
            v[a] = i;
            update(1, 0, n-1, i);
        }
    }

    for(auto el: res) cout << el << " ";
    cout << endl;
    return 0;
} 
