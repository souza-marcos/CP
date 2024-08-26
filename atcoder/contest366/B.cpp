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
    vector<string> v(n);
    vector<int> tam(n);
    int m =0;
    for(int i = 0; i < n; i ++) {
        auto& el = v[i];
        cin>> el;
        if(i > 0){
            tam[i] = max(0, tam[i - 1] + (sz(v[i-1]) - sz(v[i])));
        }
        // cout << tam[i] << " ";
        m = max(m, sz(el));
    }
    reverse(v.begin(), v.end());
    reverse(tam.begin(), tam.end());
    
    
    // for(auto el: tam) cout << el << " ";
    // cout << endl;

    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(i >= sz(v[j])){
                if(tam[j]) tam[j] --, cout << "*";
                else cout << " "; 
            }
            else cout << v[j][i];
        }
        cout << endl;
    }
    return 0;
} 
