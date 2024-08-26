#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

const int MAX = 2e5 + 10;
const ll MOD = 1e9 + 7;
vector<ll> fact(MAX, 0);

ll fexp(ll a, ll n){
    ll res = 1;
    while(n){
        if(n&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

ll inv(ll a){
    a %= MOD;
    return fexp(a, MOD -2);
}

ll cnr(ll n, ll r){
    if(r > n) return 0;
    return (fact[n] * (inv(fact[r] * fact[n-r]))) % MOD;
}

void solve(){
    int n, k; cin >> n >> k;
    int cnt_um = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a == 1) cnt_um ++;
    }
    ll cnt = 0;
    for(int i = k/2 + 1; i <=  min(cnt_um, k); i++){
        cnt += (cnr(cnt_um, i) * cnr(n - cnt_um, k - i)) % MOD;
        cnt %= MOD;
    }
    cout << cnt << endl;
}


int main(){ //_
    fact[0] = 1;
    for(int i = 1; i < MAX; i++){
        fact[i] = (i*fact[i-1]) % MOD;
    }
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
