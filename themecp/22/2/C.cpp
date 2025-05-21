#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    string a, b, c; cin >> a >> b >> c;
    vector<vector<int>> dp(sz(a) + 1, vector<int>(sz(b) + 1, -1));
    dp[0][0] = 0; // Qual o maximo se ja usei as i da a e j da b
    int n = sz(a), m = sz(b);

    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= m; j ++){
            if(i < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (c[i + j] == a[i])); 
            if(j < m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + (c[i + j] == b[j]));
        }
    }

    cout << n + m - dp[n][m] << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
