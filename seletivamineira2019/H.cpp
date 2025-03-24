#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()

#define MOD 1'000'000'009

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
struct str_hash { // 116fcb
	int P;
    const int m = MOD;

    ll compute(string const& s){
        ll hash_value = 0;
        ll ppow = 1;
        for(char c: s) {
            hash_value = (hash_value + (c - 'a' + 1) * ppow) % m;
            ppow = (ppow * P) % m;
        }
        return hash_value;
    }
};


int main(){ _

    map<pair<ll, ll>, set<ll>> dict;
    str_hash magic;
    magic.P = uniform(256, MOD - 1);

    int n, p, s; cin >> n >> p >> s;
    for(int i = 0; i < n; i ++){
        string a; cin >> a;

        string prefix, middle, suffix; 
        prefix = a.substr(0, min(p, sz(a)));
        suffix = a.substr(max(0, sz(a)-s), (s > sz(a)? sz(a) : s));
        middle = (p + s >= sz(a)) ? "" : a.substr(p, sz(a) - s - p);

        sort(middle.begin(), middle.end());
        
        ll vp = magic.compute(prefix),
           vs = magic.compute(suffix),
           vm = magic.compute(middle);


        dict[{vp, vs}].insert(vm);
    }

    int m; cin >> m;
    bool ok = true;
    for(int i = 0; i < m; i ++){
        string a; cin >> a;
        if(!ok) continue;

        string prefix, middle, suffix; 
        prefix = a.substr(0, min(p, sz(a)));
        suffix = a.substr(max(0, sz(a)-s), (s > sz(a)? sz(a) : s));
        middle = (p + s >= sz(a)) ? "" : a.substr(p, sz(a) - s - p);

        sort(middle.begin(), middle.end());

        ll vp = magic.compute(prefix),
           vs = magic.compute(suffix),
           vm = magic.compute(middle);


        if(dict.count(make_pair(vp, vs)))
        {
            auto& subSearch = dict[make_pair(vp, vs)];
            if(subSearch.count(vm)==0) ok = false;
        
        } else ok = false;
    }

    if(ok) cout << "sim\n";
    else cout << "nao\n";

    return 0;
} 
