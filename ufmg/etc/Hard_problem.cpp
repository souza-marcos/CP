#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){

    int n; cin >> n;
    vector<ll> c(n);
    for(ll& el : c) cin >> el;
    vector<string> arr(n), rev(n);

    int i = 0;  
    for(auto& el : arr) {
        cin >> el;
        rev[i] = string(el.rbegin(), el.rend());
        i ++;
    }

    ll dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for(int i = 1; i < n; i ++){
        dp[i][0] = min(
            arr[i-1] <= arr[i] ? dp[i-1][0] : LINF,
            rev[i-1] <= arr[i] ? dp[i-1][1] : LINF
        );

        dp[i][1] = min(
            arr[i-1] <= rev[i] ? dp[i-1][0] + c[i] : LINF,
            rev[i-1] <= rev[i] ? dp[i-1][1] + c[i] : LINF
        );
    }

    ll val = min(dp[n-1][0], dp[n-1][1]);
    cout << (val == LINF ? -1: val) << endl;

    // cout << ("aaaa" < "aaaa") << endl;
}
