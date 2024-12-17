#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n, x, y; cin >> n >> x >> y;
    ll elx = floor(n/(double)x), ely = floor(n/(double)y);
    ll m = (x/__gcd(x,y)) * y;  
    ll elm = floor(n/(double)m);

    elx -= elm;
    ely -= elm;
    ll res = (n + (n - elx + 1)) * elx/2;
    res -= (ely + 1) * ely/2;

    cout << res << endl; 
}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
