#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

const int MOD = 998244353;

ll binexp(ll n, ll e){
    n %= MOD;
    ll res = 1;
    while(e){
        if(e&1) res = res * n % MOD;
        n = n * n % MOD;
        e >>= 1;
    }
    return res;
}

ll inv(ll el){
    return binexp(el, MOD-2);
}

int main(){ _ 

    int n, x; cin >> n >> x;
    vector<int> t(n); for(auto& el: t) cin >> el;
    
    int maxs = x + 10;
    
    vector<ll> dp(maxs);

    ll p = inv(n);

    dp[0] = 1;
    for(int j = 0; j <= x; j ++){
        dp[j] *= p, dp[j] %= MOD;
        for(int i = 0; i < n; i ++){
            if(t[i] + j > x) continue;
            if(dp[j]) 
                dp[j + t[i]] += dp[j], dp[j + t[i]] %= MOD;
        }
    }

    ll res = 0;
    for(int i = max(0, x-t[0]+1); i <= x; i ++)
        res += dp[i], res %= MOD;

    cout << res << endl;
} 
