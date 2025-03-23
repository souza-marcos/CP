#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    ll n; cin >> n;    
    int ans = INF;

    for(ll p2 = 1; p2 <= n; p2 <<= 1)
    for(ll i = 1; p2 * i * i <= n; i ++){
        ll val = p2 * i * i;
        ans = min(ans, __builtin_popcountll(val ^ n));   
    }
    cout << ans << endl;
    return 0;
}