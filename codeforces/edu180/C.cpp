#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){
    ll n; cin >> n;
    multiset<ll> ms; 
    vector<ll> arr(n); 
    for(ll& el : arr) cin >> el;
    ll cnt = 0;
    for(int i = 1; i < n; i ++){
        for(int j = 0; j < i; j ++){
            ll sn = arr[i] + arr[j];
            auto it = lower_bound(arr.begin(), arr.end(), sn); // 
            int sx = arr.end() - it;
            int id = it - arr.begin();
            sx -= (i <= id) + (j <= id);
            cnt += sx;
        }
    }
    ll ch = n * (n-1) * (n-2) / 6;
    cout << ch - cnt << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
