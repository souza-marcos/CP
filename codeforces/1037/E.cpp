#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n; cin >> n;
    vector<int> pref(n), suff(n);
    for(int& el: pref) cin >> el;
    for(int& el: suff) cin >> el;
    if(pref[n-1] != suff[0]){
        cout << "NO\n";
        return;
    }
    
    for(int i = 0; i < n-1; i ++){
        if(pref[i] % pref[i + 1] != 0) {
            cout << "NO\n";
            return;
        }
    }

    for(int i = 0; i < n-1; i ++){
        if(suff[i+1] % suff[i] != 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}



int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
