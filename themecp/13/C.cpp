#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    int grid[2][n];
    bool used[2][n]; memset(used, 0, sizeof used);

    for(int i = 0; i < 2; i ++){
        string s; cin >> s;
        for(int j = 0; j < n; j ++){
            grid[i][j] = (s[j] == '>'? 1 : -1);
        }
    }

    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q; q.push({0, 0});
    while(sz(q)){
        auto [x, y] = q.front(); q.pop();
        if(x == 1 and y == n-1) {
            cout << "YES\n";
            return;
        }
        if(used[x][y]) continue;
        // cout << "FROM " << x << " " << y << endl;
        used[x][y] = true;

        for(auto [newi, newj] : mvs){
            newi += x, newj += y;
            if(newi < 0 or newi >= 2) continue;
            if(newj < 0 or newj >= n) continue;
            
            newj = newj + (grid[newi][newj]);
            // cout << "TO " << newi << " " << newj << endl;
            if(!used[newi][newj]) q.push({newi, newj});
        }

    }
    cout << "NO\n";
    return;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
