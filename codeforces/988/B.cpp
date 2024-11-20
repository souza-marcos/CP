#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n' 
#define sz(x) (int)x.size()

void solve(){
	int k; cin >> k;
	map<int, int> mp;
	for(int i = 0; i < k; i ++){
		int a; cin >> a;
		mp[a] ++;
	}
	
	k -= 2;
	for(auto [key, val] : mp){
		if(k % key != 0) continue;
		int other = k/key;
		if(other == key and val >= 2){
			cout << key  << " " << key << endl;
			return;
		}
		else if(mp.count(other)){
			cout << key << " " << other << endl;
			return;
		}
	}
}

int main(){ _
	int t; cin >> t;
	while(t --) solve();
    return 0;
} 
