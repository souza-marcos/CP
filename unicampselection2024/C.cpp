#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

ll gcd(ll a, ll b, ll c) {
    if(a < b) swap(a, b);
    if(a == b or b == 0) return c;
    return gcd (b, a % b, a/b + c);
}

void solve(){
    ll a, b; cin >> a >> b;
    cout << max(0ll, gcd(a, b, 0) -1) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
