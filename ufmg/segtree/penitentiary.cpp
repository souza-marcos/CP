#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f; // 1'061'109'567
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

const int MAX = 2e5 + 10;

pair<int, int> arr[MAX];
pair<int, int> seg[4 * MAX];

pair<int, int> combine(pair<int, int> a, pair<int, int> b){
    return {max(a.f, b.f), min(a.s, b.s)};
}

pair<int,int> build(int p, int l, int r){
    if(l == r) return seg[p] = arr[l];

    int m = (l + r)/2;
    return seg[p] = combine(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
}

pair<int, int> update(int i, pair<int, int> x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = x;

    int m = (l + r)/2;
    return seg[p] = combine(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}

pair<int, int> query(int ai, int bi, int p, int l, int r){
    if(ai > r or bi < l) return {-INF, INF};
    if(ai <= l and bi >= r) return seg[p];

    int m = (l + r)/2;
    return combine(query(ai, bi, 2 * p, l, m), query(ai, bi, 2 * p + 1, m + 1, r));

}

int main(){ _
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i ++){
        cin >> arr[i].f >> arr[i].s;
    }

    build(1, 0, n - 1);

    char type;
    while(q --){
        cin >> type;
        if(type == '?'){
            int l, r; cin >> l >> r; l--, r--;
            auto res = query(l, r, 1, 0, n - 1);
            if(res.s - res.f + 1 < 0) cout << 0 << endl;
            else cout << res.s - res.f + 1 << endl;
        }else{
            int i, l, r; cin >> i >> l >> r; i--;
            update(i, {l, r}, 1, 0, n - 1);
        }


    }

    return 0;
} 
