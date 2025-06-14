#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n = (int)1e6 + 2;
    const int MOD = 1e9+7;
    vector<int> twopower(n);
    twopower[0] = 1;
    for(int i = 1; i < n; i ++){
        twopower[i] = (twopower[i-1] << 1) % MOD;
    }
    
    auto w1 = [twopower](ll n) -> ll {
        return (n > 0 ?twopower[n-1] : 0);
    };

    auto w2 = [w1, MOD](ll n) -> ll {
        ll val = w1(n);
        return (val * val)%MOD;
    };
    
    vector<ll> dp1(n + 1), dp2(n + 1); 
    dp1[0] = dp2[0] = 1; 
    ll pref_dp1 = 0, pref_dp2 = 0;
    for(int i = 1; i <= n; i ++){
        pref_dp1 *= 4; pref_dp1 %= MOD;
        pref_dp1 += dp2[i-1]; pref_dp1 %= MOD;

        pref_dp2 *= 2; pref_dp2 %= MOD;
        pref_dp2 += dp1[i-1]; pref_dp2 %= MOD;
        dp1[i] = pref_dp1;
        dp2[i] = pref_dp2;
        // ll sum1 = 0, sum2 = 0;
        // for(int j = 1; j <= i; j ++){
        //     sum1 += (w2(j) * dp2[i-j]) % MOD;
        //     sum1 %= MOD;
            
        //     sum2 += (w1(j) * dp1[i-j]) % MOD;
        //     sum2 %= MOD;
        // }
        // dp1[i] = sum1;
        // dp2[i] = sum2;
    }
    // for(auto el : dp1) cout << el << " ";
    // cout << endl;

    // for(auto el : dp2) cout << el << " ";
    // cout << endl;


    int t; cin >> t;
    while(t --){
        cin >> n;
        cout << (dp1[n] + dp2[n]) % MOD << endl;
    }

    return 0;       
}
