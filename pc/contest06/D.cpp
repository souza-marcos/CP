#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
	string s; cin >> s;

	vector<vector<int>> cnt(sz(s)); // indices de comeco dos Palindromos que acabam em i

	auto add = [&](int left, int right) -> void {
		if(right >= sz(s) or left < 0) return;
		while(left >= 0 and right < sz(s) and s[left] == s[right]){
			cnt[right].push_back(left);
			left --, right ++;
		}
	};

	for(int i = 0; i < sz(s); i ++){
		cnt[i].push_back(i);
		if(i > 0) add(i-1, i+1), add(i-1, i);
	}

	ll res = 0;
	vector<int> pref(sz(s));
	for(int i = 0; i < sz(s); i ++){
		pref[i] = sz(cnt[i]) + (i > 0 ? pref[i-1] : 0);
	}

	for(int j = 0; j < sz(s); j ++){
		// cout << j << " => ";
		for(int i : cnt[j]){
			// cout << i << " ";
			res += (i > 0? pref[i-1] : 0);
		}
		// cout << endl;
	}

	cout << res << endl;
    return 0;
} 
