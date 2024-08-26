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
    int n; cin >> n;
    string s; cin >> s;
    int min_group_idx = 0, valmin = INF;
    ll sum = 0;
    

    for(int i = 0; i + 1 < n; i++){
        int group = 10 * (s[i] - '0') + (s[i + 1] - '0');
        if (group < valmin)
    }

    if(s[n-1] == 0) { cout << 0 << endl; return; }  
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
