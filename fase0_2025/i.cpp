#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int) x.size()
#define ff first
#define ss second
#define int ll

int32_t main() { _
    int n, t; cin >> n >> t;
    vector<vector<int>> v(n, vector<int>(t));
    for(int i = 0; i < n; i++) for(int j = 0; j < t; j++) cin >> v[i][j];

    int L, U; cin >> L >> U;

    vector<multiset<pair<int, int>>> best(t);
    vector<vector<int>> dp(n, vector<int>(t+1));
    for(int j = L+1; j <= t; j++){
        for(int i = 0; i < n; i++){
            for(int k = j-L; k >= max(0LL, j-U); k--){
                auto it = best[k].begin();
                auto [a, b] = *it; it++;
                auto [c, d] = *it;
                if(b == i) dp[i][j] = max(dp[i][j-1], dp[i][k]+c);
                else dp[i][j] = max(dp[i][j-1], dp[i][k]+d);
            }
            best[j].insert({dp[i][j], i});
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i][t]);
    cout << (ans == 0 ? -1 : ans) << endl;
}