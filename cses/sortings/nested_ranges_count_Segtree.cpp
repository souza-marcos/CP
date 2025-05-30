#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
 
const int MAX = 4e5+10;
namespace seg {
	int seg[4*MAX];
	int n;
    void build(int p=1, int l=0, int r=n-1){
        // if(l == r){ seg[p] = 0; return; }
        // int m = (l + r)/2;
        // build(2*p, l, m), build(2*p+1, m + 1, r);
        memset(seg, 0, sizeof seg);
    }
	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	int update(int i, int x, int p=1, int l=0, int r=n-1) {
		if (i == l and i == r) {
			return seg[p]+=x;
		}
		if (i < l or r < i) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(i, x, 2*p, l, m) +
			update(i, x, 2*p+1, m+1, r);
	}
    void print(int p=1, int l=0, int r=n-1){
        if(l == r) cout << seg[p] << " ";
        else{
            int m = (l + r)/2;
            print(p << 1, l, m), print(p << 1 | 1, m + 1, r);
        }
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
    
    seg::n = sz(els);
 
    vector<int> contain(n), is_contained(n);
 
    sort(arr.begin(), arr.end(), [](auto& left, auto& right){
        auto [la, lb, lidx] = left;
        auto [ra, rb, ridx] = right;
 
        if(la == ra) return (lb > rb);
        else return (la < ra);
    });
 
 
    for(auto [a, b, idx] : arr){
        is_contained[idx] = seg::query(pars[b], sz(els)-1);
        seg::update(pars[b], +1);
    }
 
    sort(arr.begin(), arr.end(), [](auto& left, auto& right){
        auto [la, lb, lidx] = left;
        auto [ra, rb, ridx] = right;
 
        if(lb == rb) return la > ra;
        else return lb < rb;
    }); 
    
    seg::build();
    for(auto [a, b, idx] : arr){
        // seg::print(); cout << endl;
        contain[idx] = seg::query(pars[a], pars[b]);
        // cout << a << " - " << b << " => " << is_contained[idx] << " " << pars[b] << endl;
        seg::update(pars[a], +1);
    }
    
    for(auto el : contain)
        cout << el << " ";
    cout << endl;
 
    for(auto el : is_contained)
        cout << el << " ";
    cout << endl;
    return 0;       
}