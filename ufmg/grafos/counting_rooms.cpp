#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int vis[1010][1010];
char grid[1010][1010];
int n, m, cont = 0;

bool isValid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '.');
}

vector<pair<int, int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j){
    vis[i][j] = 1;
    for(auto [newi, newj]: mov) {
        newj += j, newi += i;
        if(isValid(newi, newj)) {
            if(!vis[newi][newj]) {
                dfs(newi, newj);
            }
        }
    }
}

int main(){ _
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
