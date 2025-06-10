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
	string s; cin >> s; reverse(s.begin(), s.end());
	int left = 1, right = n;
	vector<int> res;
	for(auto ch : s){
		if(ch == '<'){
			res.push_back(left ++);
		} else {
			res.push_back(right --);
		}
	}
	res.push_back(left);
	reverse(res.begin(), res.end());
	for(auto el : res) cout << el << " ";
	cout << endl;
}

int main(){ _ 
	int t; cin >> t;
	while(t --) solve();
    return 0;
} 
