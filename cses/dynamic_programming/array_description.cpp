#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, m; cin >> n >> m;
    vector<vector<ll>> dp(2, vector<ll>(m+1));
    int cur = 1;
    const int MOD = 1e9 + 7;

    int a; cin >> a;
    if(a == 0) fill(dp[0].begin()+1, dp[0].end(), 1);
    else dp[0][a] = 1;

    for(int i = 1; i < n; i ++){
        int a; cin >> a;
        fill(dp[cur].begin(), dp[cur].end(), 0);
        if(a == 0){
            for(int j = 1; j <= m; j++){
                dp[cur][j] += dp[cur^1][j];
                if(j>1) dp[cur][j] += dp[cur^1][j-1];
                if(j<m) dp[cur][j] += dp[cur^1][j+1];
                dp[cur][j] %= MOD;    
            }
        }
        else{
            dp[cur][a] = dp[cur^1][a];
            if(a>1) dp[cur][a] += dp[cur^1][a-1];
            if(a<m) dp[cur][a] += dp[cur^1][a+1];
            dp[cur][a] %= MOD;
        }
        // for(auto el : dp[cur]) cout << el << " ";
        // cout << endl;
        cur ^= 1;
    }
    ll res = 0;
    for(auto el : dp[cur^1]) res += el;
    cout << res % MOD << endl;
    return 0;       
}
