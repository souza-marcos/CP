#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    ll n, m; cin >> n >> m;
	ll ans = 0;
	for (int i = 0; i <= 30; ++i) {
		ll x = n & ((1ll << (i + 1)) - 1);
		ll t = (1ll << i) - x;
		if (n >= (1ll << i)) {
			t = min(t, x + 1);
		}
		if (x >= (1ll << i) || t <= m) {
			ans |= (1ll << i);
		}
	}
	cout << ans << endl;
}

int main(){ _
    // int t; cin >> t;
    // while(t --) solve();
    solve();
    return 0;
} 
