#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);

#define sz(x) (int)x.size()
vector<ll> arr;

void solve(){
    int n; cin >> n;
    ll sum = 0;
    arr.resize(n); 
    for(auto & el : arr) cin >> el, sum += el;
    if(n == 1 or n == 2) return cout << -1 << endl, (void)0;
    sort(arr.begin(), arr.end());
    
    double old_average = sum/(double)n;
    ll lim_val = arr[n/2];

    auto unhappy = [&](ll x){
        return (lim_val < (old_average + x/(double)n)/2.0);
    };

    ll l = -1, r = 1e18 + 1;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(unhappy(m)) r = m;
        else l = m;
    }
    cout << r << endl;

    // cout << lim_val << " , " << old_average << " => " << old_average + r/(double)n << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
