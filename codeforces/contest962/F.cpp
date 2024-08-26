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
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);

    for(auto& el: a) cin >> el;
    for(auto& el: b) cin >> el;

    priority_queue<tuple<int, int, int>> pq; //val, index
    for(int i =0; i < n; i++){
        pq.push({a[i], max(a[i] -b[i], 0), i});
    }

    ll res = 0;
    while(k --){
        auto [val, diff, i] = pq.top();
        pq.pop();

        res += val;
        pq.push({diff, max(diff - b[i], 0), i});
    }
    cout << res << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
