#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
#define int ll
#define endl '\n'
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _ 

int n, m; cin >> n >> m;
// Count the number of ways to find the t in s as subsequence, 
// I can mod the string t at most one character. 
const int MOD = 1e9 + 7;

string s, t; cin >> s >> t;

vector<vector<array<ll, 2>>> dp(n+1, vector<array<ll, 2>>(m+1, array<ll, 2>()));

dp[0][0][0] = 1;

for(int i = 0; i < n; i ++){
    for(int j = 0; j <= m; j ++){
        
        if(dp[i][j][0] == 0 and dp[i][j][1] == 0) continue;

        (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
        (dp[i + 1][j][1] += dp[i][j][1]) %= MOD;
        
        if(j < m and s[i] == t[j]){ // Não dei match em t inteira
            (dp[i+1][j+1][0] += dp[i][j][0]) %= MOD; 
            (dp[i+1][j+1][1] += dp[i][j][1]) %= MOD;
        }

        if(dp[i][j][0]){
            if(j < m){

                (dp[i+1][j][1] += (dp[i][j][0] * 25) % MOD) %= MOD;
                if(s[i] != t[j]) {
                    (dp[i+1][j+1][1] += dp[i][j][0]) %= MOD;
                }
            }
            else 
                (dp[i+1][j][1] += 25 * dp[i][j][0] % MOD) %= MOD;
        }
    }
}
    cout << (dp[n][m][1] + dp[n][m][0])%MOD << endl;
}