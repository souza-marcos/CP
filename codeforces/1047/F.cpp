#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

namespace seg {
    vector<ll> seg;
    int n;
	void build(int m) {
        n = m;
        seg.assign(4*n + 5, 0);
	}

	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}

	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p] = x;
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};

void solve(){
    
    int n; cin >> n;
    vector<int> a(n), b(n);
    
    seg::build(3*n+10);

    for(int& el : a) cin >> el;
    for(int& el : b) cin >> el;

    vector<int> st, comeca(n, -1);
    for(int i = 0; i < n; i ++){
        while(sz(st) > 0 and a[st.back()] < a[i]){
            st.pop_back();
        }
        if(sz(st) > 0)
            comeca[i] = st.back();
        st.push_back(i);
    }

    ll res = 0;
    for(ll i = 0; i < n; i ++){
        ll final = seg::query(b[i], 2*n+10);
        if(a[i] == b[i]) 
            res += (i+1) * (n-i);
        else if(a[i] > b[i])
            res += (comeca[i] + 1) * (n-i);
        else res += final  * (n-i); 

        seg::update(a[i], a[i], i+1);
    }

    cout << res <<  endl;
}



int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
