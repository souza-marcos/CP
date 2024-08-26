#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

const int MAX = 1e5 + 10;

#define ti tuple<ll, ll, ll> // preffix, sum, suffix

ll arr[MAX];
ti seg[4 * MAX]; 
ll max_sum[4 * MAX];

void combine(int p){
    auto [af, bf, cf] = seg[2 * p];
    auto [as, bs, cs] = seg[2 * p + 1];

    max_sum[p] = max(max_sum[2 * p], max(max_sum[2 * p + 1], cf + as));

    seg[p] = {
        max(af, bf + as),
        bf + bs,
        max(cf + bs, cs),
    };
}

void build(int p, int l, int r){

    if(l == r){
        seg[p] = {arr[l], arr[l], arr[l]};
        max_sum[p] = arr[l];
        return;
    }

    int m = (l + r)/2;
    build(2 * p, l, m), build(2 * p + 1, m + 1, r);
    combine(p);
}

void update(int i, ll x, int p, int l, int r){
    if(i < l or i > r) return;
    if(l == r) {
        seg[p] = {x, x, x};
        max_sum[p] = x;
        return;
    }

    int m = (l + r)/2;
    update(i, x, 2*p, l, m), update(i, x, 2*p + 1, m+1, r);
    combine(p);
    return;
}

int main(){ _

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> arr[i];

    build(1, 0, n -1);
    cout << (max_sum[1] > 0? max_sum[1]: 0) << endl;

    while(m --){
        int i, v; cin >> i >> v;
        update(i, v, 1, 0, n - 1);
        cout << (max_sum[1] > 0? max_sum[1]: 0) << endl;
    }

    return 0;
} 
