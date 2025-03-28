#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MOD = 998244353;

ll inline getMOD(ll a ){
    return ((a%MOD) + MOD) % MOD;
}

void solve(){
    
    int n, m, d; cin >> n >> m >> d;
    vector<vector<bool>> grid(n, vector<bool>(m));
    for(int i=0; i < n; i ++){
        string s; cin >> s;
        for(int j = 0; j < m; j ++){
            grid[i][j] = s[j]=='X';
        }
    }

    vector<vector<pair<ll, ll>>> dp(2, vector<pair<ll, ll>>(m+1)); // Down -- Inline
    vector<vector<ll>> pref(2, vector<ll>(m+1)); // Down -- Inline 
    

    bool currow = 1;
    for(int j=0; j < m; j ++){
        pref[currow][j+1] = getMOD(grid[n-1][j] + pref[currow][j]);
        dp[currow][j].first = grid[n-1][j];
    }
    for(int j=0; j < m; j ++)
        if(grid[n-1][j])
            dp[currow][j].second = getMOD
            (pref[currow][min(j+d+1, m)] 
            - pref[currow][max(j-d, 0)]
            - dp[currow][j].first);
    

    for(int i = n-2;i >= 0;i--){
        // for(int j = 0; j < m; j ++){
        //     cout << "[" << dp[currow][j].first << ", " << dp[currow][j].second << "] ";
        // }
        // cout << endl;

        // Prefix sum the down line 
        for(int j = 0; j < m; j ++){
            pref[currow][j+1] = getMOD(pref[currow][j] + dp[currow][j].first + dp[currow][j].second);    
        }

        currow = !currow;
        
        // Down 
        for(int j = 0; j < m; j ++){
            
            if(grid[i][j]){
                dp[currow][j].first = getMOD
                    (pref[!currow][min(j+d-1+1, m)]
                    - pref[!currow][max(j-d+1, 0)]);

            }else dp[currow][j] = {0, 0};
            
            pref[currow][j+1] = getMOD(
                pref[currow][j] + dp[currow][j].first);    
            
        }

        // Inline
        for(int j = 0; j < m; j ++){    
            if(grid[i][j]){
                dp[currow][j].second = getMOD(
                    pref[currow][min(j+d+1, m)]
                    - pref[currow][max(j-d, 0)]
                    - dp[currow][j].first);
            }
        }
    }

    ll res = 0;
    for(int i =0; i <m; i ++){
        res = getMOD(res + dp[currow][i].first + dp[currow][i].second);
        // cout << "[" << dp[currow][i].first << ", " << dp[currow][i].second << "] ";
    }
    // cout << endl;
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
