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
	
	const int MAX = 1e6 + 10;
	vector<int> div(MAX);
	iota(div.begin(), div.end(), 0);
	vector<int> primos;

	for(int i = 2; i < MAX; i ++){
		if(div[i] == i){
			primos.push_back(i);
			for(int j = 2*i; j < MAX; j += i){
				div[j] = i;
			}
		}
	}

	auto factors = [&](int a) -> vector<int>{
		vector<int> res;
		if(a == 1) return {};
		while(a > 1){
			res.push_back(div[a]);
			int b = div[a];
			while(a % b == 0) a = a/b;
		}
		return res;
	};

	map<int, int> cnt;
	map<int,set<int>> inverted;
	int n; cin >> n;
	vector<bool> ison(MAX, false);

	for(int i:primos) {
		inverted[0].insert(i);
		cnt[i] = 0;
	}
	for(int j = 0; j < n; j ++){
		int a; cin >> a;
		
		auto fac = factors(a);
		if(ison[a]) {
			ison[a] = false;
			for(int i:fac) {
				inverted[cnt[i]].erase(i);
				if(inverted[cnt[i]].empty()) inverted.erase(cnt[i]);

				inverted[cnt[i]-1].insert(i);
				cnt[i]--;
			}
		} else {
			ison[a]=true;
			for(int i:fac) {
				inverted[cnt[i]].erase(i);
				if(inverted[cnt[i]].empty()) inverted.erase(cnt[i]);

				inverted[cnt[i]+1].insert(i);
				cnt[i]++;
			}
		}

		cout << inverted.rbegin()->ff << '\n';
	}


}