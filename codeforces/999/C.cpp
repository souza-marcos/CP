#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n; cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i ++) cin >> arr[i];
    vector<ll> dp(n+1); // Formas do iesimo ser honesto
    dp[0] = 1;
    const int MOD = 998244353;
    for(int i = 0; i < n; i ++){
        // anterior pode ser honesto 
        if((i == 0 and arr[0] == 0) or (arr[i-1] == arr[i]))
            dp[i+1] += dp[i];
        
        // Sou honesto e o anterior eh desonesto
        if(i == 1 or (i >= 2 and arr[i-2] + 1 == arr[i])) 
            dp[i+1] += (dp[i]-dp[i-1]);

        dp[i+1] = max(dp[i+1], 0ll);
        dp[i+1] %= MOD;
    }
    cout << (dp[n] + dp[n-1])%MOD << endl;
    for(auto el: dp) {
        cout << el <<" ";
    }
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
