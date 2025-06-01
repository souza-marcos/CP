#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n; cin >> n;
    int grid[n][n];
    const int MOD = 1e9 + 7;
    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        for(int j = 0; j < n; j ++){
            grid[i][j] = 0;
            if(s[j]=='*') continue;
            if(i == 0 and j == 0) grid[0][0] = 1;
            if(i>0) grid[i][j] = grid[i-1][j]; 
            if(j>0) grid[i][j] += grid[i][j-1];
            grid[i][j] %= MOD;
        }

    }
    cout << grid[n-1][n-1] << endl;
    return 0;       
}
