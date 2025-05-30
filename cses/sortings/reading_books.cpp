#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n; cin >> n;
    vector<ll> arr(n); for(ll& el : arr) cin >> el;
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    ll maxel = *max_element(arr.begin(), arr.end());
    ll rest = sum - maxel;
    if(maxel > rest) cout << 2 * maxel << endl;
    else cout << sum << endl;
    return 0;       
}
