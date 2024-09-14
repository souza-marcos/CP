#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

ll fast_pow(ll x, ll e, ll p){
    x %= p;
    ll res = 1;
    while (e > 0) {
        if (e & 1)
            res = res * x % p;
        x = x * x % p;
        e >>= 1;
    }
    return res;
}

int main(){ _
    ll n; cin >> n;
    ll MOD = 998244353;

    // digits
    ll k = n, r = 1;
    while(k) k /= 10, r *= 10;

    ll ans = n * (fast_pow(r, n, MOD)) * ()

    return 0;
} 
