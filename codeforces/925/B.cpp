#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll 

int32_t main(){ _
    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        vector<ll> arr(n); 
        for(int i = 0; i < n; i ++){
            ll a; cin >> a;
            arr[i] = (i > 0 ? arr[i-1] : 0) + a;
        }

        bool ok = 1;
        ll x  = arr.back()/n;
        int i = 1;
        for(ll el : arr) {
            if(el < x * i) ok = false;
            i ++;
        }
        cout << (ok? "YES\n" : "NO\n");
    }

} 
