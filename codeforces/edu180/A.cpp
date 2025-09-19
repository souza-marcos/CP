#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){
    int a, x, y; cin >> a >> x >> y;
    if(x > y) swap(x, y);
    if(a < x or a > y){
        cout << "YES\n";
    }else cout << "NO\n";
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
