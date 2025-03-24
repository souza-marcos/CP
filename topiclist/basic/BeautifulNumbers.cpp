// https://codeforces.com/contest/300/problem/C
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
const int MOD = 1e9 + 7;

ll mul(ll a, ll b){ a %= MOD, b %= MOD; return (a * b) % MOD; }
ll add(ll a, ll b){ a += MOD, b += MOD; return (a + b) % MOD; }

ll binexp(ll a, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = mul(ans, a);
        a = mul(a, a);
        e >>= 1;
    }
    return ans;
}

ll inv(ll a){ return binexp(a, MOD - 2); }

const int MAX = 2e6;
ll fact[MAX], ifact[MAX]; 

int main(){ _ 
    fact[0] = 1;
    for(int i = 1; i < MAX; i ++) fact[i] = mul(i, fact[i-1]);
    ifact[MAX-1] = inv(fact[MAX-1]);
    for(int i = MAX-2; i >= 0; i --) ifact[i] = mul(i+1, ifact[i+1]);


    auto choose = [&](ll a, ll b){
        return mul(mul(fact[a], ifact[b]), ifact[a-b]);
    };
    ll a, b, n; cin >> a >> b >> n;

    auto good = [a, b](ll n){
        if(n == 0) return false;
        while(n){
            if(n%10 != a and n%10 != b) return false;
            n /= 10;
        }
        return true;
    };

    // Calc the sum and check the sum is a good number
    int res = 0;
    for(int i = 0; i <= n; i ++){
        ll sum = a * i + b * (n-i);
        // cout << sum << " ";
        if(good(sum)) res = add(res, choose(n, i));
    }
    cout << res << endl;
}