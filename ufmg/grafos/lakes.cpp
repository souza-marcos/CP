#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
int lake[1010][1010];
bool vis[1010][1010];
vector<pair<int,int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool validate(pair<int, int> pos){
    return (pos.first >= 0 and pos.first < n and pos.second >= 0 and pos.second < m);
}

int dfs(pair<int,int> pos){
    vis[pos.first][pos.second] = true;
    if(lake[pos.first][pos.second] == 0) return 0;

    int cost = lake[pos.first][pos.second];
    for(auto cur_mov: moves) {
        cur_mov.first += pos.first, cur_mov.second += pos.second;
        if(validate(cur_mov) && !vis[cur_mov.first][cur_mov.second]){
            if(lake[cur_mov.first][cur_mov.second]) cost += dfs(cur_mov);
            else vis[cur_mov.first][cur_mov.second] = true;
        }
    }
    return cost;
}

void solve(){
    memset(lake, 0, sizeof lake);
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            cin >> lake[i][j];
        }
    }

    int max_cost = -INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            if(!vis[i][j]) max_cost = max(dfs({i, j}), max_cost);
        }
    }
    cout << max_cost << endl;

}

int main(){ _
    int t; cin >> t;
    while (t--)
        solve();
    

    return 0;
} 
