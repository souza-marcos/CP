#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MOD = 1e9 + 7;
ll binpow(ll a, ll e) {
    ll res = 1;
    while(e){
        if(e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

int32_t main(){
    int n; cin >> n;
    if(n&1) cout << 0 << endl, exit(0);
    n /= 2;

    vector<ll> fact(2 * n + 1), ifact(2 * n + 1);
    fact[0] = 1;
    for(ll i = 1; i <= 2*n; i ++) 
        fact[i] = fact[i-1] * i % MOD;

    ifact[2*n] = binpow(fact[2*n], MOD - 2);
    for(ll i = 2*n-1; i >= 0; i --)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;

    auto nCk = [&](ll n, ll k) -> ll {
        return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
    };

    auto catalan = [&](ll n) -> ll {
        return binpow(n+1, MOD-2) * nCk(2*n, n) % MOD;
    };

    // for(int i = 1; i <= n; i ++) cout << catalan(i) << " ";
    // cout << endl;
    cout << catalan(n) << endl;
}
