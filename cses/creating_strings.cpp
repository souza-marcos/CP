// https://cses.fi/problemset/task/1715
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MOD = 1e9 + 7;

ll fexp(ll el, ll n){
    ll res = 1;
    while(n){
        if(n & 1) res *= el; 
        el *= el;
        if(res >= MOD) res %= MOD;
        if(el >= MOD) el %= MOD; 
        n >>= 1;
    }
    return res;
}

int main(){ _
    string s; cin >> s;
    map<char, int> mp;
    for(auto c: s) mp[c] ++;

    vector<ll> fact(sz(s)+1);
    fact[0]=fact[1]=1;
    for(int i = 2; i <= sz(s); i ++){
        fact[i] = (i * fact[i-1]) % MOD;
    }
    vector<int> cnt;
    ll res = fact[sz(s)];
    for(auto [k,val]:mp)
        if (val > 1) cnt.push_back(val);

    for(auto el: cnt){
        res *= fexp(fact[el], MOD-2);
        if(res >= MOD) res %= MOD;
    }
    
    cout << res << endl;
    return 0;
} 
