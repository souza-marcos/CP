#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    
    int n, m; cin >> n >> m;
    vector<pair<int, int>> points(n);
    for(auto &[x, rd] : points) cin >> x;
    for(auto &[x, rd] : points) cin >> rd;
    sort(points.begin(), points.end());

    map<ll,ll> mp; 
    ll res = 0;
    for(auto [x, rd] : points){
        for(ll i = -rd; i <= rd; i ++){
            ll cnt = floor(sqrt((double)rd*rd - i*i));
            if(cnt >= 1) cnt = 2 * cnt;
            cnt ++;

            ll vl = mp[x+i];
            if(cnt > vl) res += cnt - vl, mp[x + i] = cnt;
        }
    }

    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
