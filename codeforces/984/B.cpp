#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> k >> n;

    vector<ll> mp(n + 1); 
    for(int i= 0; i < n; i ++){
        int b, c; cin >> b >> c;
        mp[b] += c;
    }

    sort(mp.rbegin(), mp.rend());
    ll res = 0;
    for(int i = 0; i < min(k, n); i ++){
        res += mp[i];
    }
    cout << res << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
