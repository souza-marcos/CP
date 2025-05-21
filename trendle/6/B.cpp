#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> arr(n);
    for(auto& [a, b] : arr) cin >> a;
    for(auto& [a, b] : arr) cin >> b;

    sort(arr.begin(),arr.end());

    for(auto [a, b] : arr){
        if(a > k) break;
        k += b;
    }
    cout << k << endl;
}

int main(){ _ 
    
    int t; cin >> t;
    while(t --) solve();
} 
