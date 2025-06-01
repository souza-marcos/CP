#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    ll n, x; cin >> n >> x;

    map<ll, int> pref_vals;
    pref_vals[0] = 1;

    ll cnt = 0, sum = 0;
    for(int i = 0; i < n; i ++){
        ll a; cin >> a; sum += a;
        ll rest = sum - x; 
        cnt += pref_vals[rest];
        pref_vals[sum] += 1;
    }
    cout << cnt << endl;
    return 0;       
}
