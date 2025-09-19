#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
	int n; cin >> n;
	int maxel = 0;
	vector<int> vel(n); 
	for(int& el : vel) cin >> el, maxel = max(maxel, el);

	vector<vector<int>> dp(n+1, vector<int>(maxel + 1, INF));
	for(int i = 0; i <= maxel; i++)
		dp[0][i] = 0;

	int minvel = INF;
	for(int i = 0; i < n; i ++){
		int mindp = INF;

		for(int j = maxel; j >= 0; j --){
			mindp = min(mindp, dp[i][j]);
			minvel = min(minvel, vel[i]);
			if(j == vel[i]) dp[i+1][j] = mindp; // Colocando na fila mais rapida
			if(j > vel[i]) dp[i+1][j] = dp[i][j] + (vel[i] - minvel); // Colocando na fila mais devagar 
			if(j < vel[i]) dp[i+1][j] = dp[i][j] + (vel[i] - j); // Pode colocar na fila mais rapida mas não muda o estado
		}
	}
	int res = INF;
	for(int el : dp[n]) res = min(res, el);
	cout << res << endl;
}

int main(){ _
	int t; cin >> t;
	while(t --) solve();
    return 0;
} 
