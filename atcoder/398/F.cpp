#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
int uniform(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}


template <int MOD> struct str_hash {
    static int P;
    vector<ll> h, p;
    str_hash(string s) : h(sz(s)), p(sz(s)) {

        p[0] = 1, h[0] = s[0];
        for(int i = 1; i < sz(s); i ++){
            p[i] = p[i-1] * P % MOD, 
            h[i] = (h[i-1]*P + s[i]) % MOD;
        }

    }

    ll get_hash(int l, int r){
        ll hash = h[r] - (l ? h[l-1]*p[r-l+1]%MOD : 0);
        return (hash + MOD)%MOD;
    }

};

template<int MOD> int str_hash<MOD>::P = uniform(256, MOD-1);

int main(){ _

    const int MOD = 1e9 + 7;
    // We need to find the longest suffix palindrome, maybe using hash?

    string s; cin >> s;
    string r = s; 
    reverse(r.begin(), r.end());

    str_hash<MOD> s1(s), s2(r);

    int n = sz(s);

    for(int i = 0; i < n; i ++){
        ll h1 = s1.get_hash(i, n-1);
        ll h2 = s2.get_hash(0, n-i-1);
        if(h1 == h2){
            cout << s;
            for(int j=n-i; j < n; j ++) cout << r[j];
            cout << endl;
            return 0;
        }
    }



    return 0;
} 
