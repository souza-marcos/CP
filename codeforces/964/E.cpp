#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const int MAX = 2e5 + 10;
vector<ll> f(MAX), pre(MAX);

void solve(){
    ll l, r; cin >> l >> r;
    ll cnt = f[l] + pre[r] - pre[l-1];
    cout << cnt << endl;
}

int main(){ _
    f[0] = 0; pre[0] = 0;
    for(int i = 1; i <MAX; i++){
        f[i] = f[i/3] + 1;
        pre[i] = pre[i - 1] + f[i];
    }
    
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
