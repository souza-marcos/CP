#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    
    // Longest commom subsequence

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m); 
    for(int& el : a) cin >> el;
    for(int& el : b) cin >> el;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            dp[i+1][j+1] = max({
                dp[i][j] + (a[i] == b[j]),
                dp[i+1][j],
                dp[i][j+1]
            });
        }
    }

    vector<int> res;
    int i = n, j = m;
    while(i > 0 and j > 0){
        if(a[i-1] == b[j-1]) res.push_back(a[i-1]), i--, j--;
        else {
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }
    cout << dp[n][m] << endl;
    reverse(res.begin(), res.end());
    for(auto el: res) cout << el << " ";
    cout << endl;
    return 0;       
}
