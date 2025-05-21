#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


void solve(){
    int n; cin >> n;
    string s; cin >> s;    
    ll maxv = 0;
    vector<vector<ll>> dp(n, vector<ll>(3, 0)); 
    dp[0] = {0, s[0]!='0', s[0]!='0'?0:n-1}; 
    maxv = max({dp[0][0], dp[0][1], dp[0][2]});
    for(int i = 1; i < n; i ++){
        int el = s[i] - '0';
        if(el){ // do meio eh zero
            dp[i][0] = 0,
            dp[i][1] = dp[i-1][2] + 1,
            dp[i][2] = 0;
        }else{
            dp[i][0] = dp[i-1][0] + dp[i-1][1] + i,
            dp[i][1] = 0,
            dp[i][2] = (i < n-1? dp[i-1][2] + (n-i-1) : 0);
        }
        maxv = max({maxv, dp[i][0], dp[i][1], dp[i][2]});
    }
    // for(auto row : dp){
    //     for(auto el : row )  cout << el << " ";
    //     cout << endl;
    // }

    cout << maxv << endl;
}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
