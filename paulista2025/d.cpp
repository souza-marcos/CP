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
	int n,m,p,s;
	cin >> n >> m >> p >> s;

	set<pair<int,int>> st;
	while(m--) {
		int a,b;
		cin >> a >> b;
		if(a>b) swap(a,b);
		
		if(b<=p) continue;
		if(a>p and b<=p+s) continue;
		st.insert({a,b});
	}

	int ans=0,e=n-p-s;
	vector<int> ex;
	for(int x=0;x<(1<<e);x++) {
		bool ok = true;
		for(int i=0;i<e;i++) {
			for(int j=i+1;j<e;j++) {
				if((x&(1<<i)) and (x&(1<<j)) and st.count({p+s+i+1,p+s+j+1})) {
					ok = false;
					break;
				}
			}
			if(ok==false) break;
		}
		if(ok) ex.push_back(x);
	}

	for(int i=1;i<=p;i++) {
		for(int j=p+1;j<=p+s;j++) {
			if(st.count(make_pair(i,j))) continue;
			for(int ext:ex) {
				bool ok = true;
				for(int k=0;k<e;k++) {
					if((ext&(1<<k)) and (st.count({i,k+p+s+1}) or st.count({j,k+p+s+1}))) {
						ok = false;
						break;
					}
				}
				if(ok) ans++;
			}
		}
	}

	cout << ans << '\n';
	exit(0);
}