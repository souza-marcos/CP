// https://codeforces.com/contest/378/problem/C
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n, m, k;
vector<string> game;
vector<vector<bool>> vis;

bool valid(int i, int j){
    return (min(i, j) >= 0 and i < n and j < m and game[i][j] == '.');
}
vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j){
    vis[i][j] = true;
    for(auto [newi, newj] : mvs){
        newi += i, newj += j;
        if(valid(newi, newj) and !vis[newi][newj]){
            dfs(newi, newj);
        }
    }
    if(k > 0) game[i][j] = 'X', k--;
}

int main(){ _
    cin >> n >> m >> k;
    game.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> game[i];
    }

    vis.assign(n, vector<bool>(m, 0));

    auto run = [&]() {
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(game[i][j] != '.') continue;
                if(!vis[i][j]) dfs(i, j);
                if(k <= 0) return;
            }
        }
    };

    run();
    for(int i = 0; i < n; i ++){
        cout << game[i] << endl;
    }
    return 0;
} 
