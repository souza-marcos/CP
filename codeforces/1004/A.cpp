#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int x, y; cin >> x >> y;
    if(y == x + 1) {
        cout << "Yes\n"; return;
    }
    if(y >= x) {
        cout << "No\n"; return;
    }
    x = x + 1 - y;
    if(x%9 == 0) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main(){ _

    int t; cin >> t;
    while(t --) solve();
}