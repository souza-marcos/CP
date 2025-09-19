#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n, x; cin >> n >> x;
    vector<int> arr(n); for(int& el : arr) cin >> el;
    vector<int> dp(x + 1);
    dp[0]=1;
    const int MOD = 1e9+7;
    for(int i = 0; i < x; i ++){
        for(int el : arr){
            if(i + el <= x) dp[i + el] = (dp[i+el] + dp[i]) % MOD; 
        }
    }
    cout << dp[x] << endl;
    return 0;       
}
