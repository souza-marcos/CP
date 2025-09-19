#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


int main(){ _ 
	int n; cin >> n;
	vector<tuple<int, int, int>> arr(n);
	int maxm = -INF;
	for(auto& [p, a, b] : arr) 
		cin >> p >> a >> b, 
		maxm = max(maxm, a + p);

	vector dp(n+1, vector<int>(maxm+1));
	iota(dp[n].begin(), dp[n].end(), 0);

	for(int i = n-1; i >= 0; i --){
		for(int j = 0; j <= get<0>(arr[i]); j ++)
			dp[i][j] = dp[i+1][j+get<1>(arr[i])];
		
		for(int j = get<0>(arr[i]) + 1; j <= maxm; j ++)
			dp[i][j] = dp[i+1][max(0,j-get<2>(arr[i]))];
	}

	vector<int> pref(n);
	for(int i = 0; i < n; i ++)
		pref[i] = (i > 0? pref[i-1] : 0) + get<2>(arr[i]);

	auto query = [&](int x) -> int {

		if(x <= maxm) 
			return dp[0][x];

		// tenho que diminuir enquanto esta acima do valor maximo
		int rem = x - maxm;
		auto it = lower_bound(pref.begin(), pref.end(), rem);
		if(it == pref.end()){
			return x - pref[n-1];
		}
		int idx = it - pref.begin();

		return dp[idx+1][max(0, x-pref[idx])];
	};


	int q; cin >> q;
	while(q --){
		int x; cin >> x;
		cout << query(x) << endl;
	}

	// for(auto row : dp){
	// 	for(int el : row) cout << el << " ";
	// 	cout << endl; 
	// }

    return 0;
} 
