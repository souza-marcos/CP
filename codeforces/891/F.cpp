#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n, a; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i ++) cin >> a, mp[a] ++;

    int q; cin >> q;
    while(q --){
        ll x, y; cin >> x >> y;

        ll disc = x * x - 4 * y;
        // cout << "DISC: " <<disc << endl;
        if(disc < 0) cout << 0 << " ";
        else if(disc == 0){
            if(x%2 == 0){
                ll root = x/2;
                ll res = mp[root];
                res = res*(res-1)/2;
                cout << res << " ";
            }else cout << 0 << " ";
        } else{
            ll test = sqrt(disc);

            // cout << "TEST: " << test << endl;; 
            if(test * test == disc){

                // cout << x%2 << " " << test%2 << endl;
                if(!((x%2 == 0 and test%2 == 0) or (x%2 != 0 and test%2 != 0))){
                    cout << 0 << " "; 
                    continue;
                }
                
                ll r1 = (x + test)/2;
                ll r2 = (x - test)/2;

                // cout << "ROOTS: " << r1<< " " << r2 << endl;

                ll cnt1 = mp[r1], cnt2 = mp[r2];
                cout << cnt1 * cnt2 << " ";
            }else cout << 0 << " ";
        }
    }
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
