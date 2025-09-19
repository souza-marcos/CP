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
	string s;
	cin >> s;

	if(s[3]=='S' and s[4]=='P') cout << "S\n";
	else if(s[3]=='?') {
		if(s[4]=='P') cout << "T\n";
		else cout << "N\n";
	} else if(s[4]=='?') {
		if(s[3]=='S') cout << "T\n";
		else cout << "N\n";
	} else cout << "N\n";
	exit(0);
}