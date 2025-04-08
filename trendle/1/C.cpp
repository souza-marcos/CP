#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto& el : grid) {
        cin >> el;
    }

    vector<vector<int>> ans(n, vector<int>(m));
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            int pos = 4 - (i == 0) - (j == 0) - (i == n-1) - (j == m-1);
            // cout << i << " " << j << " " << pos << endl;
            if(grid[i][j] == 'W') ans[i][j] = 2 + (pos % 2 != 0);
            else ans[i][j] = 2 + (pos % 2 != 1);
        }
    }

    cout << 1 << endl;
    for(auto row: ans){
        for(auto el : row) cout << el;
        cout << endl;
    }

} 
