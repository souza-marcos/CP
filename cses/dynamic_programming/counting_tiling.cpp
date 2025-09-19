#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

#pragma GCC optimize("O3")

int dp[1002][1 << 10];
int32_t main(){ _ 
	int n, m; cin >> n >> m;
	if(m < n) swap(n, m);
	// ok masks - segmentos de 1 de tamanho par
	vector<bool> ok_masks(1 << n);
	vector<int> valid_masks;

	auto ison = [](int mask, int i) -> bool{
		return ((mask >> i) & 1);
	};	
	for(int mask = 0; mask < (1 << n); mask ++){
		bool ok = true;
		for(int j = 0; j < n; j ++){
			if(ison(mask, j)){
				if(j == n-1 or not ison(mask, j+1)){
					ok = false;
					break;
				}
				else j++;
			}
		}
		if(ok) {
			ok_masks[mask] = 1,
			valid_masks.push_back(mask);
		}
	}
	
	for(int mask : valid_masks)
		dp[0][mask] = 1;

	const int MOD = 1e9 + 7;
	for(int i = 1; i <= m; i ++){
		for(int mask = 0; mask < (1 << n); mask ++){
			int res = 0;
			for(int submask : valid_masks){
				if((submask | mask) != mask) continue;
				int to_test = ((1 << n) - 1) ^ submask ^ mask;
				res += dp[i-1][to_test];
				if(res >= MOD) res -= MOD;
			}
			dp[i][mask] = res;
		}
	}
	cout << dp[m][0] << endl;;
}