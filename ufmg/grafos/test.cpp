#include <bits/stdc++.h>
using namespace std;

int n, m, cont  = 0;
int vis[1010][1010];
char grid[1010][1010];

bool isValid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '.');
}

vector<pair<int, int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


void dfs (int i, int j) {
    vis[i][j] = 1;
    for (auto [newi, newj]: mov) {
        newj += j, newi += i;
        if (isValid(newi, newj)) {
            if (!vis[newi][newj]) {
                dfs(newi, newj);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            cin >> grid[i][j]; vis[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                cont ++;
            }
        }
    }
    cout << cont << endl;
    

    return 0;
}
