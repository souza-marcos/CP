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
    vector<int> v(n * 2);
    for(auto& el : v) cin >> el;
    sort(v.begin(), v.end());

    n <<= 1;

    ll minval = LINF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            ll sum = 0, cur = -1;
            for(int k = 0; k < n; k ++){
                if(k == i or k == j) continue;
                if(cur == -1) cur = v[k];
                else {
                    sum += abs(v[k] - cur);
                    cur = -1;
                }
            }
            minval = min(minval, sum);
        }
    }
    cout << minval << endl;
    return 0;
} 
