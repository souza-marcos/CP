#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<int> v(n); for(auto&el : v) cin >> el;
    set_t conj;
    for(int i = n; i > 0; i--){
        conj.insert(i);
    }
    reverse(v.begin(), v.end());
    for(auto el: v){
        int val = *(conj.find_by_order(el));
        conj.erase(val);
        cout << val << endl;
    }

    return 0;
} 
