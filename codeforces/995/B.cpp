#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    ll n;
    ll v[3]; cin >> n >> v[0] >> v[1] >> v[2];

    auto valid = [&](ll days) -> bool {
        int m = days / 3;
        int res = days % 3;
        ll cnt = m * (v[0] + v[1] + v[2]);
        for(int i = 0; i < res; i ++) cnt += v[i];
        return (cnt >= n);
    };

    ll l = 0, r = 1e9 + 10;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
