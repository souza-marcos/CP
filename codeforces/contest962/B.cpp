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
    vector<vector<bool>> v(n, vector<bool>(n, 0));
    for(auto& row: v){
        string s; cin >> s;
        for(int i = 0; i < n; i ++){
            row[i] = (s[i]=='1');
        }
    }

    for(int i = 0; i < n; i += k){
        for(int j=0; j< n; j += k){
            cout << v[i][j];
        }cout << endl;
    }

    

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
