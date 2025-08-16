#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

// No need segtree, it is possible with fenwick tree in difference array
vector<ll> fenwick;

// Each index refers to [g(i), i], g(i) = i
void build(vector<ll>& arr){
    fenwick.assign(sz(arr), 0);
    for(int i = 0; i < sz(arr); i ++){
        fenwick[i] += arr[i];
        int next = i | (i + 1);
        if(next < sz(arr)) 
            fenwick[next] += fenwick[i];
    }
}

// returns the [0, k] summation
ll query(int k){
    ll res = 0;
    while(k >= 0){
        res += fenwick[k];
        k = (k & (k + 1)) - 1;
    }
    return res;
}

// Updating the difference array indexed by BIT
void update(int l, int r, ll delta){
    r ++;
    while(l < sz(fenwick)){
        fenwick[l] += delta;
        l = l | (l + 1);
    }

    while(r < sz(fenwick)){
        fenwick[r] -= delta;
        r = r | (r + 1);
    }
}

int main(){ _ 
    int n, q; cin >> n >> q;
    vector<ll> arr(n), diff(n);
    for(int i = 0; i < n; i ++){
        ll a; cin >> a;
        diff[i] = arr[i] = a;
        diff[i] -= (i > 0 ? arr[i-1] : 0ll) ;
    }

    build(diff);

    while(q --){
        int t; cin >> t;
        if(t == 1){
            ll l, r, delta; cin >> l >> r >> delta;
            l --, r --;
            update(l, r, delta);
        } else {
            int k; cin >> k; k--;
            cout << query(k) << endl;
        }
    }
    return 0;
} 
