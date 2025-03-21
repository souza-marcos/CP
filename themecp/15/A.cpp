#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n, m;
vector<vector<int>> grid, vis;
vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int i, int j){
    vis[i][j] = true;
    int val = 0;
    for(auto [newi, newj] : mvs){
        newi += i, newj += j;
        if(min(newi, newj) >= 0 and newi < n and newj < m and vis[newi][newj] == 0 and grid[newi][newj] > 0){
            val += dfs(newi, newj);
        }
    }
    return val + grid[i][j];
}


void solve(){
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    vis.assign(n, vector<int>(m, 0));

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> grid[i][j];
        }
    }

    int maxv = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(!vis[i][j] and grid[i][j] > 0) 
                maxv = max(maxv, dfs(i, j));
        }
    }

    cout << maxv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
