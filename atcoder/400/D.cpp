#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ //_
    
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto& el: grid){
        cin >> el;
    }
    int a, b, c, d; cin >> a >> b >> c >> d;
     a--, b--, c--, d--;

    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int, int>> q; q.push({c, d});
    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    dist[c][d] = 0;

    auto dfs = [&](auto&& dfs, pair<int, int> v, pair<int, int> p) -> void{
        // cout << "DFS: " << v.first << " " << v.second << endl;
        if(grid[v.first][v.second] == '#') return;
        q.push(v);
        dist[v.first][v.second] = dist[p.first][p.second];
        for(auto [newx, newy] : mvs){
            newx += v.first, newy += v.second;
            if(min(newx, newy) < 0 or newx >= n or newy >= m or dist[newx][newy] < INF) continue;

            dfs(dfs, {newx, newy}, v);
        }
    };

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(auto [newx, newy] : mvs){
            
            for(int i = 1; i <= 2; i ++){
                int nextx = x + i * newx, nexty = y + i * newy;

                if(min(nextx, nexty) < 0 or nextx >= n or nexty >= m)
                    continue;

                // cout << "BFS: " << nextx << " " << nexty << endl;

                if(dist[nextx][nexty] < INF) continue;
                dist[nextx][nexty] = dist[x][y] + 1;
                
                if(grid[nextx][nexty] == '.')
                    dfs(dfs, {nextx, nexty}, {x, y});
                else q.push({nextx, nexty});

                for(auto [x,y] : mvs){
                    x += nextx, y += nexty;
                    if(min(x, y) < 0 or x >= n or y >= m) continue;
                    
                    if(grid[x][y] == '.' and dist[x][y] == INF)
                        dfs(dfs, {x, y}, {nextx, nexty});
                }
            }

        }
    }

    cout << dist[a][b] << endl;

    // for(auto row : dist){
    //     for(auto el : row) cout << el << " ";
    //     cout << endl;
    // }

    return 0;
} 
