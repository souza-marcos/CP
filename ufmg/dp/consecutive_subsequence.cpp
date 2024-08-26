#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define pii pair<int, int>

using namespace std;

int main() { _
	int n; cin >> n;
	vector<int> a(n);
	for(auto& el: a) cin >> el;
	map<int, int> dp;

    pii ans = {0, 0}; // Size, last val
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		dp[x] = dp[x - 1] + 1;
		if (dp[x] > ans.first) {
			ans.first = dp[x];
			ans.second = x;
		}
	}
	
    stack<int> res;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == ans.second) {
			res.push(i);
			ans.second --;
		}
	}
    
    cout << ans.first << endl;
	while(!res.empty()) { cout << res.top() + 1 << " "; res.pop(); }
    cout << endl;
	return 0;
}