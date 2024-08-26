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
    int vec[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> vec[i][j];
        }
    }

    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int maxval = 0;
            for(auto [newi, newj] : mvs){
                newi += i, newj += j;
                if(newi < 0 or newi >= n or newj < 0 or newj >= m) continue;
                maxval = max(vec[newi][newj], maxval);
            }
            int diff = vec[i][j] - maxval;
            vec[i][j] -= max(0, diff);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << vec[i][j] << " ";
        } cout << endl;
    }

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
