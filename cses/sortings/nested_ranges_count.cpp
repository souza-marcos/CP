#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

int32_t main(){ _ 

    int n; cin >> n;
    vector<tuple<int, int, int>> arr(n); 

    set<int> els;
    int i = 0;
    for(auto& [a, b, idx] : arr) 
        cin >> a >> b, idx = i ++, els.insert(a), els.insert(b);


    map<int, int> pars;
    i = 0;
    for(auto el : els) pars[el] = i++, assert(el >= 0);    
    
    Bit btt(sz(els));

    vector<int> contain(n), is_contained(n);

    sort(arr.begin(), arr.end(), [](auto& left, auto& right){
        auto [la, lb, lidx] = left;
        auto [ra, rb, ridx] = right;

        if(la == ra) return (lb > rb);
        else return (la < ra);
    });


    for(auto [a, b, idx] : arr){
        is_contained[idx] = btt.query(pars[b], sz(els)-1);
        btt.update(pars[b], +1);
    }

    sort(arr.begin(), arr.end(), [](auto& left, auto& right){
        auto [la, lb, lidx] = left;
        auto [ra, rb, ridx] = right;

        if(lb == rb) return la > ra;
        else return lb < rb;
    }); 
    
    btt = Bit(sz(els));
    for(auto [a, b, idx] : arr){
        contain[idx] = btt.query(pars[a], pars[b]);
        btt.update(pars[a], +1);
    }
    
    for(auto el : contain)
        cout << el << " ";
    cout << endl;

    for(auto el : is_contained)
        cout << el << " ";
    cout << endl;
    return 0;       
}
