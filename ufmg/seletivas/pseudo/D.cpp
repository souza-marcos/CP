#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int n, m; 
vector<string> g;
vector<vector<bool>> vis;
vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j, char c){
    return (i >= 0 and i < n and j >= 0 and j < m and c == g[i][j]);
}

bool dfs(int i, int j, int pi, int pj){
    vis[i][j] = true;
    for(auto [newi, newj] : mvs){
        newi += i, newj += j;
        if(newi == pi and newj == pj) continue;
        if(valid(newi, newj, g[i][j])){
            if(vis[newi][newj]) return true;
            if(dfs(newi, newj, i, j)) return true;
        }
    }
    return false;
}

int main(){ _
    cin >> n >> m;
    g.resize(n), vis.resize(n, vector<bool>(m, false));
    for(string& t: g) cin >> t;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            if(!vis[i][j] and dfs(i, j, i, j)) { cout << "Yes\n"; return 0; }
        }
    }
    cout << "No\n";
    return 0;
} 
