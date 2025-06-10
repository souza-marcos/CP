#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _

	int t; cin >> t;
	while(t --){
		int cnt = 0;
		ll n; cin >> n;
		while(n >= 2){
			ll l = 1, r = 1e9;
			while(l + 1 < r){
				ll m = (l + r)/2;
				ll delta = (m-1)*3;
				ll last = 2 + delta, begin= 2;
				ll sum = (begin + last) * m /2;
				if(sum > n) r = m;
				else l = m;
			}
			ll delta = (l-1)*3;
			ll last = 2 + delta, begin= 2;
			ll sum = (begin + last) * l /2;
			// cout << n << " SUM " << sum << endl;;
			n -= sum;
			cnt ++;
		}
		cout << cnt << endl;
	}
    return 0;
} 
