#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<ll> arr(n);
    for(auto& el: arr) cin >> el;
    for(auto& el: arr){
        ll a; cin >> a;
        el -= a;
    }

    ll val = *max_element(arr.begin(), arr.end());
    vector<int> res;
    for(int i = 0; i < n; i++){
        if(arr[i]== val) res.push_back(i+1);
    }
    cout << sz(res) << endl;
    for(auto el : res) cout << el << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
