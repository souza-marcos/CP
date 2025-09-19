#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
const int maxn = 2e5 + 10;

vector<ll> arr;
vector<ll> fenwick;
// each indice represents [g(i), i], where g(i) = i & (i + 1). 
// So the intuition is every indice gets your trailing zeros flipped.

// To point update we have to fix the positions where that point is computed.
// -> Every i | (i + 1) < n  

// Another point is the building, naively will be O(n log n) but remark the addition of vals
// will be in other, so we can accumulate just updating the next interval associated with the present O(n).

void build(){
    int n = sz(arr);
    fenwick.assign(n, 0);
    for(int i = 0; i < n; i ++){
        fenwick[i] += arr[i];
        int next = i | (i + 1);
        if(next < n) fenwick[next] += fenwick[i];
    }
}

ll query(int l, int r){
    l--;
    ll res = 0;
    while(r >= 0){
        res += fenwick[r];
        r = (r & (r + 1)) - 1; 
    }
    while(l >= 0){
        res -= fenwick[l];
        l = (l & (l + 1)) - 1; 
    }
    return res;
}

void update(int k, ll x){
    ll delta = x - arr[k];
    arr[k] = x;
    while(k < sz(fenwick)){
        fenwick[k] += delta;
        k = k | (k + 1);
    }
}

int main(){ _

    int n, q; cin >> n >> q;
    arr.resize(n);
    for(auto &el : arr) cin >> el;

    build();

    while(q --){
        
        int t, a, b; cin >> t >> a >> b;
        if(t == 1){
            a --;
            update(a, b);
        } else {
            a--, b--;
            cout << query(a, b) << endl;
        }
    }
    return 0;
} 
