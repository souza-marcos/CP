#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto& el: grid){
        cin >> el;
    }
    int a, b, c, d; cin >> a >> b >> c >> d;
     a--, b--, c--, d--;

    vector<vector<int>> dist(n, vector<int>(m, INF));
    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    dist[c][d] = 0;
    deque<pair<int, int>> dq;
    dq.push_back({c, d});

    auto valid = [&](int newx, int newy) -> bool {
        return !(min(newx, newy) < 0 or newx >= n or newy >= m);
    };

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    while(sz(dq)){
        auto [x, y] = dq.front(); dq.pop_front();
        if(vis[x][y]) continue;
        vis[x][y] = true;

        for(auto [newx, newy] : mvs){
            newx += x, newy += y;   
            if(!valid(newx, newy) or grid[newx][newy] == '#')  continue;
            if(dist[newx][newy] > dist[x][y]){
                dist[newx][newy] = dist[x][y];
                dq.push_front({newx, newy});
            }
        }

        for(auto [newx, newy] : mvs) {
            for(int i = 1; i <= 2; i ++){
                int nextx = x + i * newx,nexty = y + i * newy;

                if(!valid(nextx, nexty)) continue;
                if(dist[nextx][nexty] <= dist[x][y] + 1) continue;

                dist[nextx][nexty] = dist[x][y] + 1;
                // if(grid[nextx][nexty] == '#') 
                dq.push_back({nextx, nexty});
                // else dq.push_front({nextx, nexty});
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
