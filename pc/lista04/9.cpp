#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const int lim = 2e6 + 10;
const int MOD = 1300031;

vector<ll> fact(lim);

ll mdc(ll a, ll b, ll& x, ll& y){
    if(b == 0) { x=1, y =0; return a;}
    ll x1, y1;
    ll d = mdc(b, a%b, x1, y1);
    x=y1, y = x1 - y1 *(a/b);
    return d;
}

ll inv(ll a){
    ll x, y;
    ll d = mdc(a, MOD, x, y);
    assert(d == 1);
    x = (x % MOD + MOD) % MOD;
    return x;
}

void calc(){
    fact[0] = 1;
    for(int i = 1; i < lim; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve(){
    int n, k; cin >> n >> k;
    cout << ((fact[n + k -1] * inv(fact[k])) % MOD) * inv(fact[n-1]) % MOD  << endl;
}

int main(){ _
    calc();
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
