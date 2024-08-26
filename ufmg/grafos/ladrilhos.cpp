#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
const int MAX = 201;
vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int tab[MAX][MAX];
bool vis[MAX][MAX];

bool valid(int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m) return false;
    return true;
}

int dfs(int i, int j){
    vis[i][j] = true;
    int cont = 1;
    
    for(auto [newi, newj] : mvs){
        newi += i, newj += j;
        if(valid(newi, newj) and tab[newi][newj] == tab[i][j] and !vis[newi][newj]){
            cont += dfs(newi, newj);
        }
    }
    return cont;
}


int main(){ _
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            cin >> tab[i][j]; vis[i][j] = false;
        }
    }

    int minv = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j]) minv = min(minv, dfs(i, j));
        }
    }

    
    // for(int i = 0; i< n; i++) {
    //     for(int j = 0; j<m; j++) cout << vis[i][j] << " ";
    //     cout << endl;
    // }
    cout << minv << endl;

    return 0;
} 
