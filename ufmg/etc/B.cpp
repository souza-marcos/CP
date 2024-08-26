#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

// ll fexp(ll a, ll b, ll p){
//     if (b == 0) return 1;
//     ll x = fexp(a, b / 2, p);
//     if(b & 1) return (x * x % p) * a % p;
//     return x * x % p;
// }

int main(){ _

    int t; cin >> t;
    ll MOD = (1e9 + 7);
    while (t --)
    {
        ll a, b; cin >> a >> b;
        ll ans = 1;
        while(b--)
            ans = ans * a % MOD;
        cout << ans << endl;
    }
    
    return 0;
} 
