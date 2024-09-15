#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const int MOD = 1e9 + 7;

void solve(){

    string s;
    cin >> s;

    int n = s.size();
    vector<int> sum(n + 1);
    vector<int> cnt(2 * n + 2, 0);

    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == '1' ? 1 : -1);
    }

    ll res = 0;
    for (int j = 1; j <= n; j++) {
        cnt[sum[j - 1] + n] += j;
        res = (res + (ll)cnt[sum[j] + n] * (n - j + 1)) % MOD;
    }

    cout << res << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}