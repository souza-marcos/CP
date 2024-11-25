// https://cses.fi/problemset/task/1079
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 10;
vector<ll> fact(MAX), ifact(MAX);

ll fexp(ll el, int n){
    ll res = 1;
    while(n){
        if(n&1) res *= el;
        el *= el;
        if(res >= MOD) res %= MOD;
        if(el >= MOD) el %= MOD;
        n >>= 1;
    }
    return res;
}

ll inline inv(ll el) { return fexp(el, MOD-2); }

int main(){ _
    fact[0]=fact[1] =1;
    for(int i=2; i <MAX; i++) {
        fact[i]=fact[i-1]*i;
        if(fact[i] >= MOD) fact[i] %= MOD;
    }

    int n; cin >> n;
    while(n --){
        int a, b; cin >> a >> b;
        cout << (fact[a] * inv(fact[b])%MOD) * inv(fact[a-b]) %MOD << endl;
    }

    return 0;
} 
