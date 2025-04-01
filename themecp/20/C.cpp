#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n, cur; cin >> n >> cur;
    ll dp[n+1][3][2]; 

    vector<ll> arr(n); for(auto&el : arr) cin >> el;
    sort(arr.begin(), arr.end());


    auto absorve = [&](ll maxval, ll power) -> ll {
        if(maxval > power) return maxval + power/2;
        return 0;
    } ;

    memset(dp, -INF, sizeof dp);

    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < 3; j ++)
            dp[0][j][i] = cur;

    for(int i = 1; i <= n; i ++){
        // double 
        for(int j = 1; j >= 0; j --){
            dp[i][2][j] = max(dp[i][2][j], absorve(dp[i-1][2][j], arr[i-1]));

            dp[i][1][j] = max(dp[i][1][j], absorve(dp[i-1][1][j], arr[i-1]));
            dp[i][1][j] = max(dp[i][1][j], absorve(2 * dp[i-1][2][j], arr[i-1]));
            
            dp[i][0][j] = max(dp[i][0][j], absorve(dp[i-1][0][j], arr[i-1]));
            dp[i][0][j] = max(dp[i][0][j], absorve(2 * dp[i-1][1][j], arr[i-1]));
            dp[i][0][j] = max(dp[i][0][j], absorve(4 * dp[i-1][2][j], arr[i-1]));
        }

        // triple
        for(int j = 2; j >= 0; j --){
            dp[i][j][1] = max(dp[i][j][1], absorve(dp[i-1][j][1], arr[i-1]));

            dp[i][j][0] = max(dp[i][j][0], absorve(dp[i-1][j][0], arr[i-1]));
            dp[i][j][0] = max(dp[i][j][0], absorve(3 * dp[i-1][j][1], arr[i-1]));
        }

        dp[i][1][0] = max(dp[i][1][0], absorve(6 * dp[i-1][2][1], arr[i-1]));
        dp[i][0][0] = max(dp[i][0][0], absorve(6 * dp[i-1][1][1], arr[i-1]));
      
        dp[i][0][0] = max(dp[i][0][0], absorve(12 * dp[i-1][2][1], arr[i-1]));
    }

    // for(int i = 0; i <= n; i ++){
    //     for(int j = 0; j < 3; j ++){
    //         for(int k = 0; k < 2; k ++){
    //             cout << i << " " << j << " " << k << " => " << dp[i][j][k] << endl;
    //         }
    //     }
    //     cout << " ---------------\n";
    // }

    // for(auto el: arr) cout << el << " ";
    // cout << endl;


    for(int i = n; i >= 0; i--){
        if(dp[i][0][0] > 0){
            cout << i << endl;
            return;
        } 
    }
    cout << -1 << endl;

}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
