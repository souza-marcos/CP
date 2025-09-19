#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    ll n, t; cin >> n >> t;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;

    auto get = [&](ll chute) -> bool {
        ll count = 0;
        for(auto el : arr) {
            count += chute/el;
            if(count >= t) return true;
        }
        return false;
    };

    ll l = 0, r = 1e18 + 10;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(get(m)) r = m;
        else l = m;
    }
    cout << r << endl;

    return 0;       
}
