#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n; cin >> n;
    vector<ll> dp(n + 10);
    for(int i= 1; i<=min(6, n); i ++) dp[i] = 1;
    const int MOD = 1e9 + 7;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 6; j ++){
            dp[i+j] += dp[i];
            dp[i+j] %= MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;       
}
