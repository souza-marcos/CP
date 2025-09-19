#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n, x; cin >> n >> x;
    vector<int> arr(n); for(int& el: arr) cin >> el;
    sort(arr.begin(), arr.end());
    vector<int> dp(x + 1);
    dp[0]=1;
    const int MOD = 1e9 + 7;
    for(int el: arr){
        for(int i = 0; i < x; i ++){
            if(dp[i]==0) continue;
            if(el + i > x) break;
            dp[el + i] = (dp[el + i] + dp[i]) % MOD;
        }
    }
    cout << dp[x] << endl;
    return 0;       
}
