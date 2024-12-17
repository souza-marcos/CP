#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int h, w, d; cin >> h >> w >> d;
    vector<string> grid(h);
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    
    for(int i = 0; i < h; i ++){
        cin >> grid[i];
        for(int j = 0; j < w; j ++) if(grid[i][j] == 'H') 
            q.push({i, j, d});
    }
    int cnt = 0;
    vector<pair<int, int>> mvs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(sz(q)){
        auto [i, j, dist] = q.front(); q.pop();

        if(vis[i][j] or grid[i][j] == '#' or dist < 0) continue;
        cnt ++;
        vis[i][j] = 1;
        for(auto [newi, newj] : mvs){
            newi += i, newj += j;
            if(min(newi, newj) >= 0 and newi < h and newj < w and !vis[newi][newj])
                q.push({newi, newj, dist -1});
        }
    }
    cout << cnt << endl;

    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j ++){
    //         cout << vis[i][j] << " ";
    //     }
    
    //     cout << endl;
    // }

    return 0;
} 
