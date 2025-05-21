#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree <
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;


int main(){ _

    ordered_set st; 
    ll n, k; cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        st.insert(i);
    }

    ll ord = 0;
    for(int i = 0; i < n; i ++){
        ord = (ord + k) % sz(st);
        auto it = st.find_by_order(ord);
        cout << *it << " ";
        st.erase(it); 
    }   
    cout << endl;
    return 0;   
} 
