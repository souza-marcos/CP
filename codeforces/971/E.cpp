#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _

    int t; cin >> t;
    int n, k;
    auto calc = [&](ll l, ll r){
        return r * (r + 1) /2 - (l - 1) * l/2;    
    };

    // n = 7, k = 2;
    // for(int i = 0; i < n; i ++){
    //     ll s1 = calc(k, k + i), s2= calc(k + i + 1, k + n -1);
    //     cout << s1 << " - " << s2 << " => " << s1 - s2  << endl;
    // }

    while(t --){
        cin >> n >> k;
        ll l = 0, r = n-1;
        while(l + 1 < r){
            ll m = (l + r)/2;
            ll val = calc(k, k + m) - calc(k + m + 1, k + n -1);
            if(val < 0) l = m;
            else r = m;
        }
        ll v1 = abs(calc(k,k + l) - calc(k + l + 1, k + n-1));
        l ++;
        ll v2 = abs(calc(k,k + l) - calc(k + l + 1, k + n-1));
        
        cout << min(v1, v2) << endl;
    }
    return 0;
} 
