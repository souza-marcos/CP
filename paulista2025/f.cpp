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

vector<int> v,mx;
vector<vector<int>> adj;

int dfs1(ll i, ll p) {
	mx[i] = v[i];
	for(int u:adj[i]) {
		if(p==u) continue;
		mx[i] = max(mx[i],dfs1(u,i));
	}
	return mx[i];
}

int dfsc(int i, int p, int k) {
	int r=0;
	for(int u:adj[i]) {
		if(u==p) continue;
		if(mx[u]<=k) continue;
		r+=2+dfsc(u,i,k);
	}
	return r;
}

int dfsm(int i, int p, int k) {
	int r=0;
	for(int u:adj[i]) {
		if(u==p) continue;
		if(mx[u]<=k) continue;
		r=max(dfsm(u,i,k)+1,r);
	}
	return r;
}

int main() { _
	int n,k;
	cin >> n >> k;
	v.resize(n);
	mx.resize(n);
	adj.resize(n);
	for(int &i:v) cin >> i;
	for(int i=1;i<n;i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(0,-1);
	if(mx[0]<=k) {
		cout << "0\n";
		return 0;
	}
	int ans = dfsc(0,-1,k);
	cout << ans-dfsm(0,-1,k) << '\n';
	exit(0);
}