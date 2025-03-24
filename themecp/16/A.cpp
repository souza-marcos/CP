#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int a, b, l; cin >> a >> b >> l;

    set<int> k;
    for(ll cur1 = 1; cur1 <= l and l % cur1 == 0; cur1 *= a){
        for(ll cur2 = 1; cur2*cur1 <= l and l % (cur2 * cur1) == 0; cur2 *= b){
            k.insert((l / cur1) /cur2);
            // cout << cur1 << " " << cur2 << " " << (l/cur1)/cur2 << endl;
            if(l%b != 0) break;
        }
        if(l%a != 0) break;
    }
    cout << sz(k) << endl;
    // for (auto el : k) cout << el << " ";
    // cout << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
