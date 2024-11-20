#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n' 
#define sz(x) (int)x.size()

int main(){ _
	int n; cin >> n;
	int maxv = -1;
	vector<int> arr(n); for(int& el: arr ) cin >> el, maxv = max(maxv, el);

	vector<int> divs(maxv + 10);
	iota(divs.begin(), divs.end(), 0);

	// crivo
	for(int i = 2; i < size(divs); i ++){
		if(divs[i] < i) {
			for(int j = 2 * i; j < size(divs); j += i){
				divs[j] = i;
			}
		}
	}

	map<int, ll> mp; 
	
	
	vector<ll> dp(n, 0);
	for(int i = 0 ; i < n; i ++){
		int el = arr[i];
		while(divs[el] > 1) mp[divs[el]] , el = divs[el];
	}



    return 0;
} 
