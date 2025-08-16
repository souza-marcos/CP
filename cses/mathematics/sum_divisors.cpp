#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int INV2 = 500000004;
const int MOD = 1e9 + 7;

inline ll add(ll a, ll b){
    return (a + b) % MOD;
}

inline ll mul(ll a, ll b){
    a %= MOD, b %= MOD;
    return (a * b) % MOD;
}

int main(){ _ 
    ll n; cin >> n;

    // cout << binpow(2, 2) << " " << binpow(3, 3) << endl;
    ll res = 0;
    for(ll i = n; i > 0; ){
        // temos que agrupar os elementos que contribuem a mesma quantidade de vezes.
        // q = floor(n/d), mesmo q;

        ll q = n/i;
        ll l = n/(q+1) +1, r = n/q;
        ll sum_d = mul(mul(r-l+1, r+l), INV2);
        res = add(res, mul(q, sum_d));
        i = l-1;
    }

    cout << res << endl;
    return 0;
} 
