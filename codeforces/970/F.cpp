#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

const ll MOD = 1e9 + 7;

ll fexp(ll a, int n){
    a %= MOD;
    ll res = 1;
    while(n){
        if(n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int main(){ _
    
    int t; cin >> t;
    vector<ll> arr, pref;
    while(t --){
        int n; cin >> n;
        arr.resize(n), pref.resize(n + 1);
        pref[0] = 0;
        for(int i = 0; i < n; i ++) 
            cin >> arr[i], pref[i + 1] = (pref[i] + arr[i]) % MOD;
   

        ll res = 0;
        for(int i = 0; i < n-1; i++){
            res += (arr[i] * (pref[n] - pref[i + 1] + MOD)%MOD);
            if(res >= MOD) res %= MOD;
        }
        ll q = ((1LL * n * (n-1))/2) % MOD;
        cout << (res * fexp(q, MOD-2)) % MOD << endl;
    }
    return 0;
} 
