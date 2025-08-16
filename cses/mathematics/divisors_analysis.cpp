#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MOD = 1e9 + 7;
inline ll mul(ll a, ll b){
    a %= MOD, b %= MOD;
    return a * b % MOD;
}

inline ll mul2(ll a, ll b){
    a %= MOD-1, b %= MOD-1;
    return a*b %(MOD-1);
}

ll binpow(ll a, ll e, ll m = MOD){
    ll res = 1;
    while(e){
        if(e&1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

inline ll inv(ll a, ll m = MOD){
    return binpow(a, m-2); 
}


int main(){ _ 
    int n; cin >> n; 
    ll number_divisors = 1, sum_divisors = 1;
    ll number = 1;
    ll exp_final_ndi = 1; 
    for(int i = 0; i < n; i ++){
        int p, a; cin >> p >> a;
        number_divisors = mul(number_divisors, a + 1);
        exp_final_ndi = mul2(exp_final_ndi, a + 1); // a ^ b ^ c
        sum_divisors = mul(sum_divisors, mul(binpow(p, a+1)-1, inv(p-1)));
        number = mul(number, binpow(p, a));
    }


    ll product_divisors = binpow(number, mul(exp_final_ndi, inv(2, MOD-1))); // WRONG -> Quero manter o numero de divisores o real.
    cout << number_divisors << " " << sum_divisors << " " << product_divisors << endl;

    return 0;
} 
