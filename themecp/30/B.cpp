#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    ll b, c, d; cin >> b >> c >> d;

    vector<bool> ab(63), ac(63), ad(63);
    for(int i = 0; i < 63; i++){
        ab[i] = (b & (1ll << i));
        ac[i] = (c & (1ll << i));
        ad[i] = (d & (1ll << i));
    }

    ll res=0;
    for(int i = 0; i < 63; i ++){
        if(ab[i]==0 and ac[i]==1 and ad[i]==1) {
            cout << -1 << endl;
            return;
        }
        if(ab[i]==1 and ac[i]==0 and ad[i]==0) {
            cout << -1 << endl;
            return;
        }

        res |= (ll(ab[i] ^ ad[i]))<<i;
    }
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
