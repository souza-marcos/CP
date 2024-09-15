#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

ll bin_exp(ll a, ll e, ll p){
    a %= p;
    ll res = 1;
    while(e){
        if (e & 1) res = res * a % p;
        a = a * a % p;
        e >>= 1;
    }
    return res;
}

int main(){ _
    ll MOD = 1e9 + 7;
    int t; cin >> t;
    while(t --) {
        int l, r, k; cin >> l >> r >> k;
        int val = 9/k + 1;
        cout << (bin_exp(val, r, MOD) - bin_exp(val, l, MOD) + MOD) % MOD << endl;
    }
    
    return 0;
} 
