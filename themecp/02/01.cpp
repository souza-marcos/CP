#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<ll> arr(n); for(ll& el : arr) cin >> el;

    ll cur = 0;

    for(int i = 0; i < n; i ++){
        ll jmp = ceil((cur + 1.0)/arr[i]);
        cur = arr[i] * jmp;
    }

    cout << cur  << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
