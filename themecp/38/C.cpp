// https://codeforces.com/problemset/problem/2036/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

// Prefix OR sum + binary search in the spec columns
// Transpose the matrix first 

void solve(){
    int n, m, q; cin >> n >> m >> q; 
    
    vector<vector<int>> arr(m, vector<int>(n));

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> arr[j][i];
            if(i > 0) arr[j][i] |= arr[j][i-1];
        }
    }

    for(int i = 0; i < q; i ++){
        int k; cin >> k;
        int l = 0, r = n-1;
        
        for(int j = 0; j < k; j ++){
            
            int reg, val; string ch;
            cin >> reg >> ch >> val;
            reg --;
            auto& row = arr[reg];
            
            if(ch == "<"){
                auto it = lower_bound(row.begin(), row.end(), val);
                int pos = -1;
                if(it != row.begin()) {
                    --it;
                    pos = it - row.begin();    
                }
                r = min(r, pos);
            }
            else {
                auto it = lower_bound(row.begin(), row.end(), val + 1);
                int pos = n;
                if(it != row.end()){
                    pos = it - row.begin();
                } 
                l = max(l, pos);
            }
        }
        if(r < l) cout << -1 << endl;
        else cout << l + 1 << endl;
    }
}
    
int32_t main(){_ 
    solve();
}