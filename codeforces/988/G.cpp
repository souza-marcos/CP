#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n' 
#define sz(x) (int)x.size()

const int MOD = 998244353;

int main(){ _
	int n; cin >> n;
	int maxv = -1;
	vector<int> arr(n); for(int& el: arr ) cin >> el, maxv = max(maxv, el);

	vector<int> divs(maxv + 10);
	iota(divs.begin(), divs.end(), 0);


	// crivo
	for(int i = 2; i < sz(divs); i ++){
		if(divs[i] == i) {
			for(int j = 2 * i; j < sz(divs); j += i){
				divs[j] = i;
			}
		}
	}
	map<int, vector<int> > mp; // factors => indices 
	
	for(int i = 0 ; i < n; i ++){
		int el = arr[i];
		while(el > 1) {

			int aux = divs[el];
			mp[divs[el]].push_back(i);
			while(aux == divs[el])
				el = el/divs[el];
		}
	}

	// for(auto el : arr) cout << divs[el] << " ";
	// cout << endl;

	// for(auto &[k, val]: mp){
	// 	cout << k << " => ";
	// 	for(int el: val) cout << el << " ";
	// 	cout << endl;
	// }
	

	vector<ll> memo(n, -1);
	auto dp = [&](auto self, int i) -> int {
		if(i == 0) return 1;
		ll& p = memo[i];

		if(p != -1) return p;
		int val = arr[i];

		ll res = 0;
		set<int> vis;
		while(val > 1) {
			auto& v = mp[divs[val]];
			auto lb = lower_bound(v.begin(), v.end(), i);

			while(lb > v.begin()){
				--lb;
				if(vis.count(*lb)) continue;
				vis.insert(*lb);

				// cout << "VAL=> " << val << " - " <<  *lb << endl;
				res += self(self, *lb);
				if(res >= MOD) res %= MOD;
			}
			// int aux = divs[val];
			// while(aux == divs[val])
				val = val/divs[val];
		}
		// cout << "\t res("<<i<<") => " << res << endl; 
		return p = res;
	};

	ll res = dp(dp, n-1);
	cout << res << endl;
    return 0;
} 
