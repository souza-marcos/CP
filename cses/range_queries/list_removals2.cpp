#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

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
    int n; cin >> n;
    vector<int> arr(n);
    ordered_set s;
    for(int i =0; i < n; i ++){
        cin >> arr[i];
        s.insert(i);
    }
    for(int i = 0; i < n; i ++){
        int q; cin >> q; q--;
        auto el = *s.find_by_order(q);
        cout << arr[el] << " ";
        s.erase(el);
    }
    cout << endl;
    return 0;
} 
