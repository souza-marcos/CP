#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    ll n; cin >> n;
    ll sum = 0; const int MOD = 1e9 + 7;
    // i over n => sum = i * (n/i)
    for(ll i = 1; n/i > 0; ){
        ll l = i;
        ll r = n/(n/i);

        ll suml = (l * ((l-1) + MOD) % MOD)/2; if(suml >= MOD) suml %= MOD;
        ll sumr = r * (r+1)/2; if(sumr >= MOD) sumr %= MOD;

        ll interval_sum = (sumr - suml + MOD) % MOD;

        sum += (interval_sum * (n/i)) % MOD;
        if(sum >= MOD) sum %= MOD;
        i = r + 1;        
    }
    
    cout << sum << endl;

    return 0;
} 
