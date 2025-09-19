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
        if(e&1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
} 

int main(){ _ 
    // Number of derangements (?)
    // n! - nC1(n-1)! + nC2(n-2)! -nC3(n-3)! ...
    // n! (1 - 1/1! + 1/2! - 1/3! ...)

    ll n; cin >> n;

    // vector<ll> fact(n+1), ifact(n+1);

    // fact[0]=1;
    // for(ll i = 1; i <= n; i ++){
    //     fact[i] = fact[i-1]*i % MOD;
    // }
    // ifact[n] = binpow(fact[n], MOD - 2);
    // for(ll i = n-1; i >= 0; i --){
    //     ifact[i] = (i+1) * ifact[i+1] % MOD;
    // }

    // for(int i = 0; i <= n; i ++){
    //     cout << fact[i] << " " << ifact[i] << endl;
    // }

    // ll res = 1;
    // for(int i = 0; i <= n; i ++){
    //     res = ((res + (i % 2 == 0? +1: -1) * ifact[i]) + MOD) %MOD;
    // }
    // res = res * fact[n] % MOD;
    // cout << res << endl;
    
    vector<ll> der(n+1);
    der[0] =1, der[1] = 0;
    for(ll i = 2; i <= n; i ++){
        der[i] = (i-1) * (der[i-1] + der[i-2] % MOD) %MOD;
    }
    cout << der[n] << endl;
    return 0;
} 
