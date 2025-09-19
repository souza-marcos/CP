#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
#define ff first
#define ss second
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main() { _

	// Quero criar um dp para max que armazeno ate indice i, e passar uma sliding window pegando o intervalos possiveis
	
	int n, d; cin >> n >> d;
	vector<pair<int, int>> arr(n);
	for(auto& [a, b] : arr) cin >> a >> b;
	sort(arr.begin(), arr.end());


	map<int, ll> dp;
	dp[0]=0;

	int i = 0;//, j = 0; // Atual inicio, j => proximo a ser inserido 
	ll sum = 0;
	// while(j < sz(arr) and arr[j].first - arr[i].first <= d){
	// 	sum += arr[j].second; 
	// 	j ++;
	// }

	set<int> idx_dp = {0};

	ll mdp = -INF;
	ll maxv = sum;
	for(int j = 0; j < sz(arr); j ++){
		while(arr[j].first-arr[i].first > d){
			// remove
			sum -= arr[i].second;
			i ++;
		}
		sum += arr[j].second;
		int idx = *(--idx_dp.lower_bound(i));
		// cout << i << " " << j << " " << sum << " " << dp[idx] << " " << idx << endl;
		maxv = max(maxv, sum + dp[idx]);
		mdp = max({mdp, dp[j], sum});
		dp[j] = mdp;
		idx_dp.insert(j);
	}

	// for(auto [k, val] : dp) cout << k << " => " << val << endl;

	cout << maxv << endl;
}