// https://cses.fi/problemset/task/1072/
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

ll choose2(ll n){ return (n - 1) * n / 2; }

int main(){ _ 
    int n; cin >> n;
    cout << 0 << endl;
    for(int i = 2; i <= n; i ++){
        cout << choose2(i * i) - 4*(i-2)*(i-1) << endl;
    }
}