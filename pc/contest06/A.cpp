#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _

	ll am, az; cin >> am >> az;
	ll a, b, c; cin >> a >> b >> c;
	ll tota = 2*a + b;
	ll totb = b + 3*c;
	ll res = max(0LL, tota-am) + max(0LL, totb-az);
	cout << res << endl;

    return 0;
} 
