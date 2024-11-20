#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n' 
#define sz(x) (int)x.size()

const int MAX = 2e5 + 10;
bool isprimo[MAX];


void solve(){
	int n; cin >> n;
	vector<int> res(n);
	int j = 0;
	int marked = -1;
	for(int i = 1; i <= n; i += 2) res[j] = i, j ++;
	for(int i = 2; i <= n; i += 2) if (!isprimo[res[j-1] + i]){
		marked = i;
		break;
	}

	if(marked == -1) cout << -1 << endl;
	else{
		for(int i = 1; i <= n; i += 2) cout << i << " ";
		cout << marked << " " ;
		for(int i = 2; i <= n; i += 2) if(i != marked) cout << i << " ";
		cout << endl;
	}
}	

int main(){ _

	for(int i = 1; i < MAX; i ++) isprimo[i] = true; 
	for(int i = 2; i < MAX; i ++){
		if(isprimo[i]){
			for(ll j = 1LL*i*i; j < MAX; j += i){
				isprimo[j] = 0;
			}
		}
	}

	int t; cin >> t;
	while(t --) solve();
    return 0;
} 
