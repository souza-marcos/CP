#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
const int MOD = 1e9 + 7;

void solve(){
    ll n; int k; cin >> n >> k;

    if(k == 1) {
        cout << n%MOD << endl;
        return;
    }

    // Compute size of loop
    ll size = 2;
    ll last = 1, cur = 1;
    while(cur != 0){
        ll aux = (last + cur)%k;
        last = cur, cur = aux;
        size ++;
    }
    cout << ((size%MOD) * (n%MOD))%MOD << endl;

}

int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
