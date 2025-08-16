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
        if(fr < sn) swap(fr, sn);
    }

    ll res = LINF;
    // SOMA (1 caso)
{

    sort(arr.begin(), arr.end(), [&](auto& left, auto& right){
        return (left.first + left.second) < (right.first + right.second);
    });

    // for(auto [fr, sn] : arr) cout << fr << " " << sn << endl;

    ll mini = -1, minval = INF;
    for(int i = 0; i + 1 < n; i ++){
        if(arr[i+1].second < arr[i].first) continue;
    
        ll val = arr[i+1].first + arr[i+1].second - arr[i].first - arr[i].second;
        if(val < minval){
            mini = i;
            minval = val;
        }
    }
    if(mini > -1){
        res = minval;
        for(int i = 0; i < n; i ++){
            if(i == mini or i == mini+1) continue;
            res += arr[i].first - arr[i].second;
        }
    }
}


    // MENOS (2 e 3 caso )

{

    sort(arr.begin(), arr.end(), [&](auto& left, auto& right){
        return (left.first - left.second) < (right.first - right.second);
    });

    // for(auto [fr, sn] : arr) cout << fr << " " << sn << endl;

    ll mini = -1, minval = INF;
    for(int i = 0; i + 1 < n; i ++){
        if(arr[i].first > arr[i+i].second) continue;
    
        ll val = arr[i+1].first - arr[i+1].second + arr[i].first - arr[i].second;
        if(val < minval){
            mini = i;
            minval = val;
        }
    }
    ll myres = LINF;
    if(mini > -1){
        myres = minval;
        for(int i = 0; i < n; i ++){
            if(i == mini or i == mini+1) continue;
            myres += arr[i].first - arr[i].second;
        }
    }
    res = min(res, myres);
}
    cout << res << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
