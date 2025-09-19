#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

template<char op, class T> vector<T> FWHT(vector<T> f, bool inv = false) {
	int n = f.size();
	for (int k = 0; (n-1)>>k; k++) for (int i = 0; i < n; i++) if (i>>k&1) {
		int j = i^(1<<k);
		if (op == '^') f[j] += f[i], f[i] = f[j] - 2*f[i];
		if (op == '|') f[i] += (inv ? -1 : 1) * f[j];
		if (op == '&') f[j] += (inv ? -1 : 1) * f[i];
	}
	if (op == '^' and inv) for (auto& i : f) i /= n;
	return f;
}

int32_t main(){ _

    int n; cin >> n;
    vector<vector<pair<int, ll>>> g(n);
    for(int i = 0; i < n-1; i ++){
        int a, b, w; cin >> a >> b >> w;
        a --, b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    vector<ll> gen(n);

    const int MOD = 1e5;
    auto dfs = [&](auto&& self, int v, int p) -> void{
        for(auto [u, w]: g[v]) if(u != p) {
            gen[u] = (gen[v] + w) % MOD; 
            self(self, u, v);
        }
    };
    gen[0] = 0;
    dfs(dfs, 0, -1);
    
    vector<int> freq(1e5 + 1);
    for(auto el : gen) freq[el] ++;


    int next_size = 1;
    while(next_size < sz(freq)) next_size <<= 1;
    freq.resize(next_size);

    auto vec = FWHT<'^', ll>(freq);
    for(ll& el : vec) el *= el;
    freq = FWHT<'^', ll>(vec, true);

    gen.clear();
    for(int i = 0; i < sz(freq); i ++) 
        if(freq[i] > 0) gen.push_back(i);

    sort(gen.begin(), gen.end());
    cout << sz(gen) << endl;
    for(auto el: gen) cout << el << " ";
    cout << endl;
};  
