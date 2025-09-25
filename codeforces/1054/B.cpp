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
    vector<int> arr(n);
    for(int& el : arr) cin >> el;
    sort(arr.begin(), arr.end());
    int ma = -LINF;
    for(int i = 0; i < n; i += 2){
        ma = max(ma, arr[i + 1] - arr[i]);
    }
    cout << ma << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
