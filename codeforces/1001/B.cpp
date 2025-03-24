#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n; cin >> n;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;

    bool ok = true;
    for(int i = 0; i < n; i ++){    
        ll val = 2 * max(n - i - 1, i) + 1;
        if(val > arr[i]){
            cout << "NO\n";

            return;
        }
    }
    cout << "YES\n";
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
