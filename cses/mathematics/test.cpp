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


int main (){
    cout << inv(2, MOD -1) << " " << mul2(inv(2, MOD -1), 2) << " "  << mul(inv(2), 2) << endl;
}