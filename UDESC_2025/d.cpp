#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _
	
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y; x--, y --;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for(auto& row : grid){
        for(int& el : row) cin >> el;
    }

    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto valid = [n, m](int i, int j) -> bool {
        return min(i, j) >= 0 and i < n and j < m;
    };

    // Consigo sair de i, j e chegar a n-1, m-1 com essa restrição?
    auto can = [&](int i, int j, ll restric) -> bool { // "BFS 0-1"
        if((grid[i][j] | restric) != restric) return false;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;


        while(sz(q)){
            auto [i, j] = q.front(); q.pop();
            if(i == n-1 and j == m-1) return true;
            
            for(auto [newi, newj] : mvs){
                newi += i, newj += j;
                if(!valid(newi, newj)) continue;
                if(((grid[newi][newj] | restric) == restric) and !vis[newi][newj]){
                    vis[newi][newj] = true;
                    q.push({newi, newj});
                }
            }
        }
        return false;
    };

    auto calc = [&](int i, int j) -> int {
        ll init = (1ll << 32) - 1;
        for(int k = 31; k >= 0; k --){
            if(can(i, j, init ^ (1ll << k))){
                init ^= (1ll << k);
            }
        }
        return init;
    };
    cout << calc(0, 0) << " " << calc(x, y) << endl;
}