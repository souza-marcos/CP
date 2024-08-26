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
    int n, m; cin >> n >> m;
    string s; cin >> s;

    int max_1 = 0, max_interval = 0;
    int cur = 0, cur_interval = 0;
    for(auto c : s){
        int it = c - '0';
        
        if(it == 0) max_interval = max(max_interval, cur_interval), cur_interval = 0;
        else cur_interval ++;

        if(it == 2) cur ++;
        if(it == 0) max_1 = max(max_1, cur), cur = 0;
    }
    max_interval = max(max_interval, cur_interval);
    max_1 = max(max_1, cur);

    //cout << max_1 << " " << max_interval;
    int tot = max_1 + max(max_interval - m - max_1, 0);
    cout << tot << endl;
    return 0;
} 
