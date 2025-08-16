#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MOD = 1e9 + 7;

ll binpow(ll a, ll e){
    ll res = 1;
    while(e){
        if(e & 1) res *= a, res %= MOD;
        a *= a, a %= MOD;
        e >>= 1;
    }
    return res;
}

int main(){ _

    int n; cin >> n;
    while(n --){
        ll a, b; cin >> a >> b;
        cout << binpow(a, b) << endl;
    }

    return 0;
} 
