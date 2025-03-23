// https://codeforces.com/contest/1165/problem/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _ 
    int n; cin >> n;
    const int MOD = 998244353;
    vector<ll> a(n), b(n); 
    for(auto& el: a) cin >> el; 
    for(auto& el: b) cin >> el; 


    auto choose = [&](ll a) -> ll {
        return (a * (a + 1))/2;
    };
    ll tot = choose(n);

    for(int i = 0; i < n; i ++)
        a[i] *= tot - choose(i) - choose(n - i - 1);

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for(int i = 0; i < n; i ++){
        ans += (a[i] % MOD) * (b[i] % MOD);
        ans = (ans + MOD) % MOD;
    }

    cout << ans << endl;

}