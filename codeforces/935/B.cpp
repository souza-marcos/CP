#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    ll a, b, m; cin >> a >> b >> m;
    ll ans = 0;
    if(a > m) ans ++;
    else ans += m/a + 1;

    if(b > m) ans ++;
    else ans += m/b + 1;

    cout << ans << endl;    

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
