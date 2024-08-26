#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

void solve(){
    int n; cin >> n;
    int ans = (1 << 30)-1;
    while(n --){
        int a; cin >> a;
        ans &= a;
    }
    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
