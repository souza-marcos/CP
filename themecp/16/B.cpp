#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

#define int ll

void solve(){
    int n; cin >> n;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;
    
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    
    
    sort(arr.begin(), arr.end());
    vector<ll> diff(n-1);

    ll d = 0;
    for(int i = 0; i < n-1; i ++){
        diff[i] = arr[i + 1] - arr[i];
        d = __gcd(diff[i], d);
    }

    ll res = 0;
    for(auto el : arr) res += arr[n-1] - el;
    res /= d;


    ll minv = LINF; 

    auto search = [&](int newval, ll acc = 0ll){
        auto it = lower_bound(arr.begin(), arr.end(), newval);
        if(it== arr.end() or *it != newval){
            minv = min(minv, res + (abs(arr[n-1]-newval))/d + acc);
            // cout << newval << " " << res << " " << res + (arr[n-1]-newval)/d + acc << " " << acc << endl;
        }

    };

    for(int i = 0; i < n; i ++){
        search(arr[i]-d);
        if(i == n-1) search(arr[i] + d, n);
        else search(arr[i] + d);
    }

    cout << minv << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
