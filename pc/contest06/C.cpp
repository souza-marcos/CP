#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
	int a, b, c; cin >> a >> b >> c;
	{
		int newa = a, newb = b, newc = c;
		int dec = min(newb, newc);
		newb -= dec, newc -= dec, newa += dec;
		int diff = abs(newb - newc);
		if(diff%2 == 1){
			cout << "0 ";
		}else{
			if(newa > 0) cout << "1 ";
			else cout << "0 ";
		}
	}
	{
		int newa = a, newb = b, newc = c;
		int dec = min(newa, newc);
		newa -= dec, newc -= dec, newb += dec;
		int diff = abs(newa - newc);
		if(diff%2 == 1){
			cout << "0 ";
		}else{
			if(newb > 0) cout << "1 ";
			else cout << "0 ";
		}
	}
	{
		int newa = a, newb = b, newc = c;
		int dec = min(newb, newa);
		newb -= dec, newa -= dec, newc += dec;
		int diff = abs(newb - newa);
		if(diff%2 == 1){
			cout << "0 ";
		}else{
			if(newc > 0) cout << "1 ";
			else cout << "0 ";
		}
	}
	cout << endl;
}

int main(){ _
	int n; cin >> n;
	while(n--) solve();
    return 0;
} 
