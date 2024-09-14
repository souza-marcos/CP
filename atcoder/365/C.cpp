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
ll n, m;
vector<ll> v;
bool valid(ll middle){
    ll val = 0;
    for(auto el : v){
        val += min(middle, el);
        if(val > m) return false;
    }
    return true;
}

int main(){ _
    cin >> n >> m;
    v.resize(n); for(auto& el: v) cin >> el;
    sort(v.rbegin(), v.rend());

    ll l = 0, r = LINF;

    while(l + 1 < r){
        ll middle = (l + r)/2;
        if(valid(middle)) l= middle;
        else r = middle; 
        // cout << l << " - " << r << endl;    
    }
    if (l == LINF - 1){
        cout << "infinite\n";
    } else cout << l << endl;

    return 0;
} 
