#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

// prefix sum 2D

int main(){ _
    int n, q; cin >> n >> q;

    int grid[n][n];
    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        for(int j = 0; j < n; j ++){
            grid[i][j] = s[j] == '*';
        }
    }

    int prec[n+1][n+1];
    for(int i = 0; i <= n; i ++){
        prec[0][i] = 0;
        prec[i][0] = 0;
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            prec[i+1][j+1] = prec[i+1][j] + prec[i][j+1] + grid[i][j] - prec[i][j];
        }
    }

    while(q--){
        int y1, x1, y2, x2; cin >> x1 >> y1 >> x2 >> y2;
        int res = prec[x2][y2] - prec[x1-1][y2] - prec[x2][y1-1] + prec[x1-1][y1-1];
        cout << res << endl;
    }
    
    return 0;
} 
