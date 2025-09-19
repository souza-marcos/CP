#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int32_t main(){ _ 
    ll n, m, k; cin >> n >> m >> k;

    // Cada antidiagonal deve ser igual.
    // Problema se reduz a achar k-th seguencia considerando a menor ordem de comparação de cada antidiagonal.
    int p = n + m -1; // number of el in each path
    vector<pair<int, int>> arr(p, {INF, INF});
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            int a; cin >> a;
            arr[i + j] = min(arr[i + j], {a, i+j});
        }
    }
    sort(arr.begin(), arr.end());
    // for(auto [fr, sn] : arr) cout << fr << " " << sn << endl;

    auto check = [&](string& res){
        vector<vector<ll>> dp(p + 1, vector<ll>(p/2 + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= p; i ++){
            for(int j = 0; j <= p/2; j ++){
                if(res[i-1] == ' ') dp[i][j] = (j > 0 ? dp[i-1][j-1]:0) + (j < p/2 ? dp[i-1][j+1]:0);
                else if(res[i-1] == '(') dp[i][j] = (j > 0 ? dp[i-1][j-1]: 0);
                else dp[i][j] = (j < p/2 ? dp[i-1][j+1] : 0);
                dp[i][j] = min(dp[i][j], LINF);
            }
        }
        return dp[p][0];
    };

    string res(p, ' ');
    for(int g = 0; g < p; g ++){
        // cout << g << " " << p  << endl;
        auto [foo, curpos] = arr[g];
        res[curpos] = '(';
        ll val = check(res);
        if(val < k) {
            res[curpos] = ')';
            k -= val;
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cout << res[i + j];
        }
        cout << endl;
    }
}