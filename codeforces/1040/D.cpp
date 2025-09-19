#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

void solve(){
    int n; cin >> n;
    vector<int> arr(n); 
    
    for(int i = 0; i < n; i ++){
        int a; cin >> a; a--;
        arr[a]=i;
    }

    ord_set<int> s;
    int res = 0;

    // Following the induction by the offcial induction
    for(int i = n-1; i>=0; i--){
        int val = s.order_of_key(arr[i]);
        res += min(val, sz(s) - val);
        // cout << arr[i] << " " << val << " " << sz(s) - val << endl; 
        s.insert(arr[i]);
    }
    cout << res << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
