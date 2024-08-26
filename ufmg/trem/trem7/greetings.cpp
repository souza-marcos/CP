#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(auto& [b, a] : v)
        cin >> a >> b;
    
    sort(v.begin(), v.end());

    ordered_set st;
    ll sum = 0;
    for(auto&[b, a]: v){
        sum += st.order_of_key(a);
        st.insert(a);
    }
    cout << sum << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
