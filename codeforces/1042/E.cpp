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
    vector<int> a(n), b(n);

    for(int &el : a) cin >> el;
    for(int &el : b) cin >> el;
    bool ok = true;
    for(int i = n-1; i >= 0; i --){
        if(a[i] == b[i]) continue;
        int need = a[i]^b[i];
        if(i < n-1 and (need == a[i+1] or need == b[i+1])) continue;
        ok = false;
    }
    cout << (ok ? "YES\n": "NO\n");
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
