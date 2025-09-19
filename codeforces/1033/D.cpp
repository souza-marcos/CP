#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1e9+7;

// fast exponentiation
long long modpow(long long x,long long y=MOD-2){
    long long r=1;
    while(y){
        if(y&1) r=r*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    // We only ever need factorials up to MAXA = 1e5
    static const int MAXA = 100000;
    vector<long long> fact(MAXA+1,1), invfact(MAXA+1,1);
    for(int i=1;i<=MAXA;i++){
        fact[i] = fact[i-1]*i % MOD;
    }
    invfact[MAXA] = modpow(fact[MAXA]);
    for(int i=MAXA;i>0;i--){
        invfact[i-1] = invfact[i]*i % MOD;
    }

    while(T--){
        long long a,b,k;
        cin >> a >> b >> k;
        // 1) compute n
        long long n_big = ( (__int128)(a-1)*k + 1 ) ;  // may exceed 1e9+7
        long long n = n_big % MOD;

        // 2) compute C = C(n mod p, a) by Lucas + direct product
        long long N = n;  // this is n mod p
        // if N < a then C=0 (but that never really occurs since (a-1)*k+1 > a)
        long long numer = 1;
        for(int i = 0; i < (int)a; i++){
            numer = numer * ( (N - i + MOD) % MOD ) % MOD;
        }
        long long C = numer * invfact[a] % MOD;

        // 3) compute m
        long long m = (C * k) % MOD;
        m = (m * (b-1)) % MOD;
        m = (m + 1) % MOD;

        cout << n << " " << m << "\n";
    }
    return 0;
}
