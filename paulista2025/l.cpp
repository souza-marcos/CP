#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
#define ff first
#define ss second
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main() { _
	int n;
	cin >> n;
	if(n!=2) {
		cout << "S\n";
		return 0;
	}

	vector<int> v1,v2;
	int k1,k2;
	cin >> k1;
	for(int i=0;i<k1;i++) {
		int x;
		cin >> x;
		v1.push_back(x);
	}
	cin >> k2;
	for(int i=0;i<k2;i++) {
		int x;
		cin >> x;
		v2.push_back(x);
	}

	while(v2.size()) {
		v1.push_back(v2.back());
		v2.pop_back();
	}

	bool b = false;
	for(ull i=0;i<v1.size();i++) {
		if(v1[i]==1 and b) {
			cout << "N\n";
			return 0;
		}
		if(v1[i]==2) b=true;
	}

	cout << "S\n";
	exit(0);
}