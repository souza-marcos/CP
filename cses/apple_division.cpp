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

int main(){ _

    int n; cin >> n;
    vector<ll> v(n); for(auto& el : v) cin >> el;
    ll sum_all = accumulate(v.begin(), v.end(), 0LL);
    ll min_diff = LINF;
    for(int mask = 0; mask < (1 << n); mask ++){
        ll sum = 0;
        for(int j = 0; j < n; j ++){
            if(mask & (1 << j)) sum += v[j];
        }
        min_diff = min(min_diff, abs(sum_all - sum - sum));
    }
    cout << min_diff << endl;
    return 0;
} 
