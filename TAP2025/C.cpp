#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _
	int n; cin >> n;
	vector<ll> cnt(n);
	for(int i = 0; i < n; i ++){
		ll a; cin >> a;
		a = (a + i) % n;
		cnt[a] ++;
	}

	ll res = n;
	for(int i = 0; i < n; i ++){

		// cout << cnt[i] << " ";
		res += cnt[i] * (cnt[i] - 1);
	}

	// cout << endl;

	cout << res << endl;
}