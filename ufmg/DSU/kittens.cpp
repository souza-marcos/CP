#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz;
vector<list<int>> res;

int find(int x){
	return id[x] = (id[x] == x? x: find(id[x]));
}

void uni(int a, int b){
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] > sz[b]) swap(a, b);
	id[a] = b;

	res[b].splice(res[b].end(), res[a]);

	sz[b] += sz[a];
}

int main(){ _
	int n; cin >> n;

	id.resize(n); sz.resize(n, 1);
	iota(id.begin(), id.end(), 0);
	
	res.resize(n);
	for(int i = 1; i <= n; i++) {
		res[i - 1].push_back(i);
	} 

	int x, y;
	while(n-- > 1){
		cin >> x >> y; x --, y --;
		uni(x, y);
	}

	x = find(x);

	for(auto el:res[x]) cout << el << " ";
	cout << endl;

	return 0;
} 
