#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _

	int t; cin >> t;
	while(t --){
		string s; cin >> s;
		int res = 0;
		for(auto ch : s) res += ch =='1';
		cout << res << endl;
	}
    return 0;
} 
