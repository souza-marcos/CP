#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    pair<int, int> start;
    for(int i = 0; i < n; i ++){
        cin >> grid[i];
        for(int j = 0; j < m; j ++){
            if(grid[i][j]=='A') start = {i, j};
            else if(grid[i][j]=='M'){
                dist[i][j]=0; q.push({i, j});
            }
        }
    }

    {
        auto [i, j] = start;
        if(min(i, j) == 0 or i == n-1 or j == m-1){
            cout << "YES\n0\n";
            return 0; 
        }
    }

    vector<pair<int, int>> mvs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    auto valid  = [&](int newi, int newj) -> bool {
        return min(newi, newj) >= 0 and newi < n and newj < m;
    };

    while(sz(q)){
        auto [i, j] = q.front(); q.pop();

        for(auto [newi, newj] : mvs){
            newi += i, newj += j;
            if(valid(newi, newj) and dist[newi][newj] == INF and grid[newi][newj] != '#'){
                dist[newi][newj] = dist[i][j] + 1;
                q.push({newi, newj});
            }
        }
    }

    vector<vector<int>> dist_person(n, vector<int>(m, INF));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    q.push(start);
    dist_person[start.first][start.second] = 0;
    pair<int, int> end = {-1, -1};
    bool ok = false;

    while(sz(q)){
        auto [i, j] = q.front(); q.pop();

        for(auto [newi, newj] : mvs){
            newi += i, newj += j;
            if(valid(newi, newj) 
                and dist_person[newi][newj] == INF 
                and dist_person[i][j] + 1 < dist[newi][newj]
                and grid[newi][newj] != '#'){
                    dist_person[newi][newj] = dist_person[i][j] + 1;
                    q.push({newi, newj}); 
                    parent[newi][newj] = {i, j};
                    if(min(newi, newj) == 0 or newi == n-1 or newj == m-1){
                        end = {newi, newj};
                        ok = true;
                        break;
                    }
                }
        }
        if(ok) break;
    }
    if(!ok) {
        cout << "NO\n";
        return 0;
    }
    string res;
    while(end != start){
        auto &[i, j] = end;
        if(min(i, j) < 0) break;
        auto [newi, newj] = parent[i][j];
        int di = newi - i, dj = newj - j;
        i = newi, j = newj;
        char ch;
        if(di == 0 and dj == 1) ch = 'L';
        else if(di == 0 and dj == -1) ch = 'R';
        else if(di == 1 and dj == 0) ch = 'U';
        else ch = 'D';
        res.push_back(ch);
    }
    reverse(res.begin(), res.end());
    cout << "YES\n" << sz(res) << endl;
    cout << res << endl;
}
