#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
	int a, b; cin >> a >> b;
	if(a > b) swap(a, b);

	vector<vector<int>> dp(a + 1, vector<int>(b + 1));
	for(int i = 1; i < a; i ++)
		dp[i][i] = 0;

	for(int i = 1; i <= a; i ++){
		for(int j = 1; j <= b; j++){
			if(i == j) continue;
			int val = INF;
			for(int k = 1; k <= i-1; k ++){
				val = min(val, dp[k][j] + dp[i-k][j] + 1);
			}
			for(int k = 1; k <= j-1; k ++){
				val = min(val, dp[i][k] + dp[i][j-k] + 1);
			}

			dp[i][j] = val;
		}
	}
	cout << dp[a][b] << endl;
    return 0;
} 
