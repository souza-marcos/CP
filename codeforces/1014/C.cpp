#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){

    int n; cin >> n;
    int par = 0, impar = 0;    
    ll sum = 0, maxv = 0;
    for(int i = 0; i < n; i ++){
        ll a; cin>> a;
        if(a&1) impar ++;
        else par ++;
        sum += a;
        maxv = max(maxv, a);
    }
    if(par and impar)
        cout << sum - (impar - 1) << endl; 
    else cout << maxv << endl;

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
