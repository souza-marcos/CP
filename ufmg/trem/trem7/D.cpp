#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
#define sz(x) (int)x.size()


int main(){_
    string s;
    cin >> s;
    int n = sz(s);
    vector<ll> dp(n + 1, 0);
    for(int i = n-1; i >= 0; i--){
        ll maxval = 0, sum = 0;
        for(int j = 1; j <= 3; j ++){
            if(i + j > n) break;
            sum += (s[i + j - 1] - '0');
            maxval = max(maxval, dp[i + j] + (sum%3 == 0));
        }
        dp[i] = maxval;
    }
    cout << dp[0] << endl;
    // for(auto el: dp) cout << el << " ";
    // cout << endl;
}