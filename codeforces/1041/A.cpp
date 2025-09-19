#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    bool ok = true;
    for(auto& el : arr){
        cin >> el;
        if(el == 0) ok = false;
    } 
    if(!ok){
        cout << "NO\n";
        return;
    }

    for(int i = 0; i+ 2 < n; i ++){
        int mn = INF, ma = -INF;
        for(int j = 0; j <= 2; j ++)
            if(arr[i+j] != -1) mn = min(mn, arr[i+j]), ma = max(ma, arr[i+j]);

        if(mn == INF or mn == ma) {
            if(mn != INF) {
                for(int j = 0; j <= 2; j ++)
                    arr[i+j] = mn;
            }
        } else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
