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
    vector<ll> arr(2*n); for(auto& el: arr) cin >> el;

    sort(arr.rbegin(), arr.rend());

    ll a = arr[0], pls = 0, mns = 0;

    vector<ll> res(2*n + 1);

    for(int i = 1; i <= n; i ++) mns+=arr[i], res[2*i] = arr[i];
    for(int i = n+1, j = 1; i < 2*n; i ++, j += 2) pls+=arr[i], res[j] = arr[i];
    res[0] = arr[0];

    ll rest = arr[0] - pls + mns;
    res[sz(res)-2] = rest;

    for(auto el: res) cout << el << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
