// https://codeforces.com/problemset/problem/1866/B
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
const int MOD = 998244353;

ll mul(ll a, ll b){ a %= MOD, b %= MOD; return (a * b) % MOD; }
ll add(ll a, ll b){ a += MOD, b += MOD; return (a + b) % MOD; }

int main(){ _ 

    int n; cin >> n;
    map<int, pair<int, int>> mp; 
    vector<int> base(n), exp(n);    
    for(auto& el: base) cin >> el;
    for(auto& el: exp) cin >> el;

    for(int i = 0; i < n; i ++)
        mp[base[i]].first = exp[i];

    cin >> n;
    base.resize(n), exp.resize(n);

    for(auto& el: base) cin >> el;
    for(auto& el: exp) cin >> el;

    for(int i = 0; i < n; i ++)
        mp[base[i]].second = exp[i];

    ll ans = 1;
    for(auto [k, val] : mp){
        auto [frs, snd] = val;
        if(frs < snd) ans *= 0;
        else if(frs > snd) ans = mul(ans, 2);
    }
    cout << ans << endl;
}