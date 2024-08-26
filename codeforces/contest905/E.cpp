#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

void solve(){
    int n; cin >> n;
    vector<ll> v(n);
    for(ll& el: v) cin >> el;

    int cnt= 0, cur = 64 - __builtin_clzll(v[0]);
    for(int i = 1; i < n; i++){
        // cout << cur << ", ";
        int val = 64 -__builtin_clzll(v[i]);
        int val_bef = 64 - __builtin_clzll(v[i-1]);


        // cout << val << " - " << cur << endl;

        if(val > cur) {
            cur = val; continue;
        }
        // val <= cur(lower bound) 

        ll aux = v[i-1] << max(0, (val - val_bef));
        // cout << "AUX: " << aux << "\n";
        if(v[i] < aux) cnt += cur - val + 1, cur ++;
        else cnt += cur - val;
        
    }
    cout << cnt << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
