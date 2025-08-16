#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll 

void solve(){

    ll n, x, y; cin >> n >> x >> y;
    map<pair<ll, ll>, ll> cnt;
    ll res = 0;
    for(int i =0; i < n; i ++){
        ll a; cin >> a;
        ll xi = ((-a % x) + x) %x, yi = a % y;

        // cout << a << " " << xi << " " << yi << endl; 
        res += cnt[{xi, yi}];
        cnt[{a%x, a%y}] ++;
    }
    cout << res << endl;
}

int32_t main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
