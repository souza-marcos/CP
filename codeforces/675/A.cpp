#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    ll a, b, c; cin >> a >> b >> c;

    if(b > a) swap(a, b);
    if(c > a) swap(a, c);
    if(c > b) swap(b, c);

    ll e = b + c;
    if(e > a) swap(e, a);
    cout << a - e + 1 << endl;

}


int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
