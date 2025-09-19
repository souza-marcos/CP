#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

	int n; cin >> n;
	string s; cin >> s;
	// Cabessa sempre empata ou ganha.

	vector<array<int, 3>> dp(sz(s) + 1, {-INF, -INF, -INF});
	dp[0] = {0, 0, 0};

	for(int i = 0; i < n; i ++){
/* S */ if(s[i] != 'R') dp[i+1][0] = max({dp[i][1], dp[i][2]}) + (s[i] == 'P');   
/* R */ if(s[i] != 'P') dp[i+1][1] = max({dp[i][0], dp[i][2]}) + (s[i] == 'S');  
/* P */ if(s[i] != 'S') dp[i+1][2] = max({dp[i][0], dp[i][1]}) + (s[i] == 'R');
	}
	cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;


	// for(auto& row : dp){
	// 	for(int el : row) cout << el << " ";
	// 	cout << endl;	
	// }
    return 0;
}
