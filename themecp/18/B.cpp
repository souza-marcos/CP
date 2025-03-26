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
    vector<ll> arr(n); for(auto& el: arr) cin >> el;


    for(ll k = 2; k <= 1e18; k <<= 1){
        set<ll> els;
        for(int i = 0; i < n; i ++){
            els.insert(arr[i]%k);
        }
        if(sz(els) == 2){
            cout << k << endl;
            return;
        }
    }




}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
