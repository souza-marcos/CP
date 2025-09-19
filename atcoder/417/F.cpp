#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

const int MOD = 998244353;
const int MAX = 2e5 +10;
namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n;
    ll *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2,ll* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		
        if(lazy[p] != 0) seg[p] = lazy[p]*(r-l+1);
		if (l != r and lazy[p]) lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

ll pow(ll x, ll y, ll m) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

int main(){ _ 
    int n, m; cin >> n >> m;
    ll arr[n]; for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 
    seg::build(n, arr);
    
    for(int i = 0; i < m; i ++){
        int l, r; cin >> l >> r; l--, r--;
        ll soma = seg::query(l , r) % MOD;
        
        ll newval = soma * pow(r-l+1, MOD-2, MOD) % MOD;
        // cout << soma << " " << newval << endl;
        seg::update(l, r, newval);
    }
    for(int i = 0; i < n; i ++){
        cout << seg::query(i,i) << " ";
    }
    cout << endl;
    return 0;
} 
