#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ 
	
	int n; cin >> n;
	vector<vector<int>> g(n);
	for(int i = 1; i < n; i ++){
		int a, b; cin >> a >> b;
		a --, b--;
		g[a].push_back(b), g[b].push_back(a);
	}

	int timer = 0;
	vector<int> tin(n), tout(n);
	vector<int> euler, pre;

	auto dfs = [&](auto& dfs, int p, int v) -> void {
		tin[v] = timer ++;
		euler.push_back(v);
		for(auto u : g[v]) {
			if(u != p) {
				dfs(dfs, v, u);
				euler.push_back(v);	timer ++;
			}
		}
		// euler.push_back(v);
		tout[v] = timer;
	};
	dfs(dfs, -1, 0);

	// pre[0] = 1;
	// for(int i = 1; i < sz(euler); i ++){
	// 	pre[i] = pre[i-1];
	// 	if(tin[euler[i]] == i) pre[i]++;  
	// 	else if(tout[euler[i]]==i)pre[i]--;
	// }
	
	for(auto el : euler) cout << el + 1 << " ";
	cout << endl;

	vector<bool> asked(n); // and obtain 
	int cur = n, start= 0;
	while(cur > 1){
		cout << start << " " << cur << endl;
		int j= start;
		set<int> query;
		int ja = 0;

		while(true){
			int next = euler[j++]; 
			if(!query.count(next)) ja ++;
			asked[next] = 1;
			query.insert(next);
			// cout << next << " " << ja << " " << sz(query) << " " << sz(query) - ja << " "  << cur/2 << endl;
			if((sz(query)-ja) > cur/2) break;
		}

		cout << "? " << sz(query);
		for(auto el: query) cout << " "  << el + 1;
		cout << endl; cout.flush();

		int res; cin >> res;
		if(res == -1) exit(0);
		if(res == 0) {
			cur = cur - sz(query), start = j;
			while(asked[euler[start]]) start ++;
		}
		else {
			cur = sz(query);
			while(asked[euler[start]]) start ++;
		}
	}
	cout << "! " << euler[start]+1 << endl;
	cout.flush();

	// cout << "RES\n";
	// for(auto el : euler) cout << el << " " << subsize[el] << endl;

} 
