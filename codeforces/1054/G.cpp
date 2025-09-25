#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll


// MO
//
// Para ter o bound abaixo, escolher
// SQ = n / sqrt(q)
// 
// O(n * sqrt(q))

const int MAX = 2e5+10;
const int SQ = sqrt(MAX);
int arr[MAX];
vector<int> freq;
vector<set<int>> inverted;

int n, q;
int l = 0, r = -1;
vector<int> res;
inline void insert(int p) {
    inverted[freq[p]].erase(arr[p]);
    
    freq[p] = freq[p] + 1;
    inverted[freq[p]].insert(arr[p]);
    res.clear();
    int tot = (r - l + 1) /3  + 1;
    if(p >= tot)
}

inline void erase(int p) {
	inverted[freq[p]].erase(arr[p]);
    
    freq[p] = freq[p] - 1;

    inverted[freq[p]].insert(arr[p]);
}

inline ll hilbert(int x, int y) {
	static int N = 1 << (__builtin_clz(0) - __builtin_clz(MAX));
	int rx, ry, s;
	ll d = 0;
	for (s = N/2; s > 0; s /= 2) {
		rx = (x & s) > 0, ry = (y & s) > 0;
		d += s * ll(s) * ((3 * rx) ^ ry);
		if (ry == 0) {
			if (rx == 1) x = N-1 - x, y = N-1 - y;
			swap(x, y);
		}
	}
	return d;
}

vector<int> MO(vector<pair<int, int>> &q) {
	l = 0, r = -1;
	int m = q.size();
	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 0);

    vector<ll> h(m);
	for (int i = 0; i < m; i++) h[i] = hilbert(q[i].first, q[i].second);
	sort(ord.begin(), ord.end(), [&](int l, int r) { return h[l] < h[r]; });

	vector<int> ret(m);

	for (int i : ord) {
		int ql, qr;
		tie(ql, qr) = q[i];
		
        while (r < qr) insert(++r);
		while (l > ql) insert(--l);
		while (l < ql) erase(l++);
		while (r > qr) erase(r--);
		int tot = (qr - ql)/3 + 1;
        ret[i] = bt.query(tot, n+1);
	}
	return ret;
}

void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i ++) cin >> arr[i];
    freq.assign(n, 0);
    inverted.assign(n + 1, {});
    
    vector<pair<int, int>> queries(q);
    for(auto& [l, r] : queries) cin >> l >> r, l--, r--;
    auto res = MO(queries);

    for(int el : res) cout << el << " ";
    cout << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
