#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n; cin >> n;
    vector<int> arr(n); for(auto& el: arr) cin >> el, el = el > 1;
    reverse(arr.begin(), arr.end());

    bool dp[n][2]; 
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i < n; i ++){
        for(int j = 0; j < 2; j ++){
            dp[i][j] = !dp[i-1][(j + 1)%2]; // pegou tudo
            if(arr[i]) dp[i][j] |= dp[i-1][j]; // largou uma
        }
    }

    cout << (dp[n-1][0] ? "First\n" : "Second\n");

    // for(int i=0; i < n; i ++) {
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }

}

int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
