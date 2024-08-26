#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;

signed main() {
    set_t d;
    d.insert(0);
    d.insert(1);
    cout << d.size() << endl;
    cout << *(d.lower_bound(1)) << endl;
    cout << d.order_of_key(1) << endl;
    cout << d.order_of_key(-1) << endl;
    cout << d.order_of_key(2) << endl;
}