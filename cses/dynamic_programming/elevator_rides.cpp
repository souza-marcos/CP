#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, limit; cin >> n >> limit;
    vector<int> weights(n); for(int& el: weights) cin >> el;

    vector<int> dp(1 << n, INF); 
    vector<bool> hasOkWeight(1 << n);

    for(int mask = 1; mask < (1 << n); mask ++){
        ll sum = 0;
        for(int bit = 0; bit < n; bit ++){
            if(mask & (1 << bit)){
                sum+=weights[bit];
            }
        }
        if(sum <= limit) 
            hasOkWeight[mask] = true;
    }

    dp[0] = 0;
    for(int mask = 1; mask < (1 << n); mask ++){
        for(int submask = mask; submask > 0; submask = (submask - 1) & mask){   
            if(hasOkWeight[submask])
                dp[mask] = min(dp[mask], dp[mask ^ submask] + 1);
        }
        // cout << dp[mask] << " ";
    }

    cout << dp[(1 << n)-1] << endl;
    return 0;       
}
