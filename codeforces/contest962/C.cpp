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
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    
    vector<vector<int>> a_cnt(n + 1, vector<int>(26, 0)), b_cnt(n+1, vector<int>(26, 0));
    
    for(int i = 1; i < n + 1; i++){
        a_cnt[i] = a_cnt[i -1];
        a_cnt[i][a[i-1]-'a'] ++; 
    
        b_cnt[i] = b_cnt[i -1];
        b_cnt[i][b[i-1]-'a'] ++;
    }

    while(q--){
        int l, r; cin >> l >> r; l--, r--;
        int cnt = 0;
        int res_a, res_b;
        for(int i = 0; i < 26; i ++){
            
            // cout << "A R: " << a_cnt[r + 1][i] << ", L: " << a_cnt[l][i] << endl;
            // cout << "B R: " << b_cnt[r + 1][i] << ", L: " << b_cnt[l][i] << endl << endl;
            res_a = a_cnt[r + 1][i] - a_cnt[l][i];
            res_b = b_cnt[r + 1][i] - b_cnt[l][i];
            
            cnt += abs(res_b - res_a);
        }
        cout << cnt /2<< endl;

    }
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
