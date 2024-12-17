#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

#define int long long 

void solve(){
    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;

    ll kn = 1;
    ll res = 0;
    while(kn <= 2e9){
        // Find the first kn that kn * r1 >= l2
        if(kn * r1 < l2){ kn *= k;  continue; }

        // Find the first i that kn * i >= l2
        int l = l1, r = r1;
        while(l + 1 < r){
            int m = (l + r)/2;
            if(m * kn < l2) l = m;
            else r = m;
        }
        int first = (l * kn >= l2? l : r);

        // Find the last i that kn * i <= r2
        l = l1, r = r1 + 1;
        while(l+1 < r){
            int m = (l + r)/2;
            if(m * kn <= r2) l = m;
            else r = m;
        }
        if(kn * l > r2) break;

        // cout << "kn = " << kn << ", [" << first << ", " << l << "]" << endl;

        res += (l - first + 1);
        kn *= k;
    }
    cout << res << endl;
}


int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
