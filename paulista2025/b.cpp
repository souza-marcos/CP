#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
#define ff first
#define vv first
#define ss second
#define cc second
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void djks1(vector<vector<pair<int,int>>> &adj, vector<int> &o, vector<ll> &ans) {
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	for(int i:o) {
		pq.push({0,i});
		ans[i] = 0;
	}

	while(not pq.empty()) {
		auto [c,v] = pq.top();
		pq.pop();
		if(ans[v]<c) continue;

		for(auto [u,w]:adj[v]) {
			if(ans[u]>ans[v]+2*w) {
				ans[u] = ans[v]+2*w;
				pq.push({ans[u],u});
			}
		}
	}
}

bool djks2(vector<vector<pair<int,int>>> &adj, vector<ll> &distp, ll x) {
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	pq.push({0,0});
	vector<ll> dist(adj.size(),LLONG_MAX);
	dist[0] = 0;

	while(not pq.empty()) {
		auto [c,v] = pq.top();
		pq.pop();

		if(dist[v]<c) continue;
		for(auto [u,w]:adj[v]) {
			if(dist[v]+w>distp[u]+x) continue;
			if(dist[u]>dist[v]+w) {
				dist[u] = dist[v]+w;
				pq.push({dist[u],u});
			}
		}
	}
	// for(int i:dist) cout << i << ' ';
	// cout << '\n';
	return dist.back()!=LLONG_MAX;
}

int main() { _
	ll n,m,k;
	cin >> n >> m >> k;
	vector<vector<pair<int,int>>> adj(n);
	
	for(ll i=0;i<m;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

	vector<int> ori(k);
	for(int &i:ori) {
		cin >> i;
		i--;
	}
	
	ll l=0,r=10'000'000'000LL,ans=LLONG_MAX;
	
	vector<ll> distp(n,LLONG_MAX);
	djks1(adj,ori,distp);
	
	while(l<=r) {
		ll m = (l+r)>>1;

		if(djks2(adj,distp,m)) {
			ans = m;
			r=m-1;
		} else l=m+1;
	}

	cout << ans << '\n';
	exit(0);
}