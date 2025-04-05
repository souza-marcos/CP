#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n; cin >> n;
    vector<ll> arr(n);
    for(auto &el: arr) cin >> el;
    
    sort(arr.begin(), arr.end());
    ll d = 0;
    for(int i = 1; i < n; i ++){
        if(arr[i]%arr[0] == 0)
            d = __gcd(d, arr[i]/arr[0]);
    }
    if(d == 1) cout << "Yes\n";
    else cout << "No\n";
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
