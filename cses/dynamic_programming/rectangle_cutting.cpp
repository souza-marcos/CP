#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    
    int a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    vector<vector<int>> dp(a+1, vector<int>(a+1, INF));

    for(int i = 1; i <= a; i ++){
        for(int j = 1; j <= b; j ++){
            if(i == j) dp[i][j] = 0;
            else {

                for(int k = 1; k < i; k ++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                for(int k = 1; k < j; k ++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;       
}
