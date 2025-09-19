#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    
    ll n; cin >> n;
    map<ll, int> pref;
    pref[0]=1;
    ll sum = 0, cnt = 0;
    for(int i = 0; i < n; i ++){
        ll a; cin >> a; a %= n; a = (a + n) % n;
        sum = (sum + a)%n;
        cnt += pref[sum];
        pref[sum] ++;
    }
    cout << cnt << endl;
    return 0;       
}
