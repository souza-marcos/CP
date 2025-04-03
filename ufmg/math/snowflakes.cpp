#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

int main(){ _
    
    vector<ll> possible;

    for(ll k = 2; k <= 1e6; k ++){
        ll cur = 1 + k + k * k, kpower = k * k * k;
        for(ll level = 3; level <= 63 and kpower <= 1e18 - cur; level ++){
            cur += kpower;
            possible.push_back(cur);
            if(1e18/k < kpower) break;
            kpower *= k;
        }
    }

    // cout << sz(possible) << endl;
    sort(possible.begin(), possible.end());

    int t; cin >> t;
    while(t --){
        ll n; cin >> n;
        auto lb = lower_bound(possible.begin(), possible.end(), n);
        if(lb != possible.end() and *lb == n) cout << "YES\n";
        else {
            // checking 1 + k + k*k == n
            ll l = 2, r = 1e9+1;
            while(l + 1 < r){
                ll m = (l + r)/2;
                if(1 + m + m*m > n) r=m;
                else l=m;
            }
            if(1 + l + l*l == n) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
} 
