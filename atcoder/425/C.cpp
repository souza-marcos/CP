#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _


    int n, q; cin >> n >> q;
    vector<ll> pref(n);
    for(int i = 0; i < n; i ++){
        cin >> pref[i];
        if(i > 0) pref[i] += pref[i-1];
    }

    int cur = 0;
    auto sum = [&](int l, int r) -> ll {
        l--, r--;
        l += cur, r += cur;
        l %= n, r %= n;
        if(r < l) {
            return pref[n-1] - pref[l-1] + pref[r]; 
        }
        else {
            return pref[r] - (l > 0 ? pref[l-1] : 0);
        }
    };

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int c; cin >> c;
            cur += c;
            cur %= n;
        }
        else{
            int l, r; cin >> l >> r;
            cout << sum(l, r) << endl;
        }
    }

    return 0;
} 
