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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for(auto &row : a){
        string s; cin >> s;
        for(int i = 0; i < sz(s); i++) row[i] = s[i];
    }
    for(auto &row : b){
        string s; cin >> s;
        for(int i = 0; i < sz(s); i++) row[i] = s[i];
    }

    // compare columns
    int sum_a = 0, sum_b = 0;
    for(int i = 0; i < m; i ++){
        sum_a = sum_b = 0;
        for(int j = 0; j < n; j++){
            sum_a = (sum_a + a[j][i]) % 3;
            sum_b = (sum_b + b[j][i]) % 3;
        }
        // cout << sum_a << " " << sum_b << endl;
        if(sum_a != sum_b) { cout << "NO\n";  return; } 
    }
    
    for(int i = 0; i < n; i ++){
        sum_a = 0, sum_b = 0;
        for(int j = 0; j < m; j++){
            sum_a = (sum_a + a[i][j]) % 3;
            sum_b = (sum_b + b[i][j]) % 3;
        }
        // cout << sum_a << " " << sum_b << endl;
        if(sum_a != sum_b) { cout << "NO\n";  return; } 
    }
    cout << "YES\n";
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
