#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, cur; cin >> n >> cur;
    vector<tuple<int, int, int>> arr(n);
    for(auto& [real, l, r] : arr){
        cin >> l >> r >> real;
    }

    sort(arr.begin(), arr.end());
    
    for(auto [real, l, r] : arr){
        if(cur >= l and cur <= r and cur < real) cur = real;
    }
    cout << cur << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
