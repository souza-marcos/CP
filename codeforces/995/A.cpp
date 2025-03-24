#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> mono(n), stereo(n);
    for(auto &el : mono) cin >> el; 
    for(auto &el : stereo) cin >> el;

    ll res = 0;
    for(int i = 0; i < n - 1; i ++){
        ll diff = mono[i]-stereo[i+1];
        if(diff>0) res += diff;
    }
    res += mono[n-1];
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
