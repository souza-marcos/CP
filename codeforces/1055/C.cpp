#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n,q; cin >> n >> q;
    vector<int> arr(n); for(int& el : arr) cin >> el;
    vector<int> pos;
    pos.reserve(n);
    
    vector<int> pref(n);
    pref[0] = arr[0];
    for(int i = 1; i < n; i ++){
        if(arr[i] == arr[i-1]) pos.push_back(i);
        pref[i] = pref[i-1] + arr[i];
    }

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l --, r --;

        if((r-l+1) % 3 != 0 or (pref[r]-(l>0?pref[l-1]:0)) % 3 != 0){
            cout << -1 << endl;
            continue;
        }
        int base = (r-l+1)/3;
        auto lb = lower_bound(pos.begin(), pos.end(), l+1);
        auto rb = lower_bound(pos.begin(), pos.end(), r);
        
        cout << base + (rb - lb == 0) << endl;
    }
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
