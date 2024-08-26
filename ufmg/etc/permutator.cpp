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
const long double PI = acos(-1);

#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<ll> a(n), b(n);

    for(auto& el : a) cin >> el;
    for(auto& el : b) cin >> el;
    for(int i = 0; i < n; i ++){
        a[i] *= ((ll)(i + 1)) * (n - i);
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    ll val = 0;
    for(int i = 0; i < n; i ++){
        val += a[i] * b[i];
    }
    cout << val << endl;
    return 0;
} 
