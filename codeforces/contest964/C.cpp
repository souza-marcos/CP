#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n, s, m; cin >> n >> s >> m;
    vector<pair<int, int>> v(n); for(auto& [l, r]: v) cin >> l >> r;

    sort(v.begin(), v.end());
    int cur = 0;
    for(int i = 0; i < n; i++){
        auto [l, r] = v[i];
        if(l - cur >= s) {cout << "YES\n"; return;}
        cur = r;
    }
    if(m - cur >= s) cout << "YES\n";
    else cout << "NO\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
