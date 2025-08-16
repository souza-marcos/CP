#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> arr(n);
    for(auto &[fr, sn] : arr) {
        cin >> fr;
    }
    for(auto& [fr, sn]: arr){
        cin >> sn;
        if(fr > sn) swap(fr, sn);
    }
    
    sort(arr.begin(), arr.end(), [&](auto& left, auto& right){
        return left.first < right.first;
    });

    ll minv = LINF;
    for(int i = 0; i+1 < n; i++){
        minv = min(minv, max(0ll, 2*(arr[i+1].first - arr[i].second)));
    }

    ll res = minv;
    for(int i = 0; i < n; i ++)
        res += arr[i].second - arr[i].first;

    cout << res << endl;

}


int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
