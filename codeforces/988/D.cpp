#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n' 
#define sz(x) (int)x.size()

void solve(){
	int n, m, l;  cin >> n >> m >> l;
	int i = 0, j = 0;

	vector<pair<int, int>> holes(n); for(auto& [l, r]:holes) cin >> l >> r;
	vector<pair<int, int>> powerup(m); for(auto &[x, val]:powerup) cin >> x >> val;

	// for(auto [l, r] : holes) cout << l << " " << r << endl;
	// for(auto [x, val] : powerup) cout << x << " " << val << endl;

	int cnt = 0;
	ll jmp = 1, cur = 1;
	multiset<int> ms; 
	while(i < n){
		while(powerup[j].first < holes[i].first and j < m) ms.insert(powerup[j].second), j ++;

		// for(auto el: ms) cout << el << " ";
		// cout << endl;

		cur = holes[i].first - 1;
		while(cur+jmp <= holes[i].second and ms.size() > 0) jmp += (*ms.rbegin()), cnt ++, ms.erase(ms.find(*ms.rbegin()));
		if (cur + jmp <= holes[i].second) {
			cout << -1 << endl;
			return;
		}
		i++;
	}
	cout << cnt << endl;
	
}	

int main(){ _
	int t; cin >> t;
	while(t --) solve();
    return 0;
} 
