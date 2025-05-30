#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n; cin >> n;
    vector<pair<int, int>> arr(n); 
    for(auto& [fr, sn] : arr) cin >> fr >> sn;

    sort(arr.begin(), arr.end());
    ll cur = 0;
    ll res = 0;
    for(auto [a, b] : arr){
        cur += a;
        res += b - cur;
    }
    cout << res << endl;
    return 0;       
}
