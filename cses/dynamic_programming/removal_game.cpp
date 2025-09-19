#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    
    int n; cin >> n;
    vector<ll> pref(n+1);
    vector<int> arr(n); 
    int i=1;
    for(int& el : arr) cin >> el, pref[i] = pref[i-1] + el, i++;

    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int i = 0; i < n; i ++)
        dp[i][i] = dp[i][i] = arr[i];

    auto get_sum = [&](int i, int j) -> ll {
        return pref[j+1] - pref[i];
    };

    for(int l = 1; l < n; l ++){
        for(int i = 0; i + l < n; i ++){
            dp[i][i+l] = max(
                get_sum(i, i+l-1) - dp[i][i+l-1] + arr[i+l], 
                get_sum(i+1, i+l) - dp[i+1][i+l] + arr[i]
            );
        }
    }
    cout << dp[0][n-1] << endl;
}
