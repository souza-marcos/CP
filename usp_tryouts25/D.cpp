#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _
    
    int n; cin >> n;
    ll g = 0;
    for(int i = 0; i < n; i ++){
        ll a; cin >> a;
        g = __gcd(a, g);
    }    
    ll res = 0;
    for(ll i = 2; i * i <= g; i += 1)


}