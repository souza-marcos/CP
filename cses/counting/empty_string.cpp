#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
const int MOD = 1e9 + 7;

ll binpow(ll a, ll e){
    ll res = 1;
    while(e){
        if(e&1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}
vector<ll> fact, ifact;

int32_t main(){ _ 

    string s; cin >> s;
    int n = sz(s);
    fact.resize(n+1), ifact.resize(n+1);

    fact[0]=fact[1] = 1;
    for(ll i = 2; i <= n; i ++){
        fact[i] = fact[i-1]*i % MOD;
    }
    ifact[n] = binpow(fact[n], MOD-2);
    for(ll i = n-1; i >= 0; i --){
        ifact[i] = ifact[i+1] * (i + 1) % MOD; 
    }

    auto nCk = [&](ll n, ll k) -> ll{
        if(n < 0 or k > n or k < 0) return 0;
        return fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;
    };
    
    vector<vector<ll>> consigo(n+1, vector<ll>(n+1));
    
    for(int i = 0; i+1 < n; i ++)
        consigo[i+1][i] = 1; // , consigo[i][i+1] = s[i] == s[i+1];

    for(int len = 2; len <= n; len += 2){
        for(int i = 0, j = i + len -1; j < n; i++, j++){
            for(int k = i+1; k <= j; k ++){    
                if(s[i] != s[k]) continue;
                ll left = (i + 1 > k-1 ? 1: consigo[i+1][k-1]), right = (k + 1 > j? 1 :  consigo[k+1][j]);
                // cout << i << " " << k << " " << j << " => " << left << " " << right  << " " << (j-i+1)/ 2 << " " << (k-i+1)/2 << " " << nCk((j-i+1)/2, (k-i+1)/2) << endl;
                consigo[i][j] += (left*right%MOD)*nCk((j-i+1)/2, (k-i+1)/2);
                consigo[i][j] %= MOD;
            }
        }
    }

    cout << consigo[0][n-1] << endl;

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < n; j ++){
    //         cout << consigo[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;       
}
