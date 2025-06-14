#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    
    string s, t; cin >> s >> t;
    // We must calculate the edit distance of a string to the other.
    // Add - Remove - Replace. The ADD op is equivalent to REMOVE

    vector<vector<int>> dp(sz(s) + 1, vector<int>(sz(t)+1));

    for(int i = 1; i <= sz(s); i ++)
        dp[i][0] = i; // We must remove the caracters of the right string

    for(int i = 1; i <= sz(t); i ++)    
        dp[0][i] = i;

    for(int i = 0; i < sz(s); i ++){
        for(int j = 0; j < sz(t); j ++){
            dp[i+1][j+1] = min({
                dp[i][j] + (s[i]!=t[j]),
                dp[i][j+1]+1,
                dp[i+1][j]+1
            });
        }
    }
    // for(int i = 0; i < sz(dp); i ++){
    //     for(int j = 0; j < sz(dp[0]); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[sz(s)][sz(t)] << endl;
    return 0;       
}
