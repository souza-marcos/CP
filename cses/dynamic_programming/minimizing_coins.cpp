#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n, x; cin >> n >> x;
    vector<ll> dp(x + 1, INF);
    vector<ll> arr(n); 
    for(ll& el : arr) cin >> el;
    sort(arr.begin(), arr.end());
    dp[0] = 0;
    for(int i = 0; i < x; i ++){
        if(dp[i] == INF) continue;
        for(auto el : arr) {
            if(i + el > x) break;
            dp[i + el] = min(dp[i+el], dp[i] + 1);
        }
    }
    cout << (dp[x]==INF?-1:dp[x]) << endl;
    return 0;       
}
