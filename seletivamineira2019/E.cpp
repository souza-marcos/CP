#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

// Segtree para guardar e atualizar os deltas
// Sumpref inicial

const int MAX = 1e5 + 10; 
namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n;

	void build(int szo) {
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));
        n = szo;
    }
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
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

int main(){ _
    int n; cin >> n;
    vector<tuple<int, int, int>> arr(n); 
    int i = 0;
    ll sum[n + 1]; sum[0] = 0;
    for(auto& [ini, w, pos]: arr) {
        cin >> pos >> w; pos--;
        ini = i ++; 
        sum[i] = sum[i-1] + w; 
    }

    // for(auto el: sum) cout << el << endl;

    // Deltas
    seg::build(n);
    sort(arr.begin(), arr.end(), [&](auto el1, auto el2){
        auto [ini1, w1, pos1] = el1;
        auto [ini2, w2, pos2] = el2;
        if(pos1 < pos2) return true;
        return false;
    }); 
    

    ll res = 0;
    for(auto [posini, w, posretirada] : arr){
        ll delta = seg::query(posini, posini);
        res += delta + (sum[posini + 1]);
        // cout << res << endl;
        if(posini > 0) seg::update(0, posini-1, w);
    }

    cout << res << endl;
    return 0;
} 
