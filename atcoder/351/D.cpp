#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int n, m;
vector<vector<bool>> g;

bool valid(int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m) return false;
    return true;
}
vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool hasN(int i, int j){
    for(auto [newi, newj]: mvs){
        newi += i, newj += j;
        if(valid(newi, newj) and g[newi][newj]) return true;
    }
    return false;
}

vector<vector<bool>> vis;

int dfs(int i, int j){
    if(hasN(i, j)) return 1;
    vis[i][j] = true;
    int sum = 0;
    for(auto [newi, newj] : mvs){
        newi += i, newj += j;
        if(valid(newi, newj) and !vis[newi][newj]) sum += dfs(newi, newj); 
    }
    vis[i][j] = false;
    return sum ;
}

int main(){ _
    cin >> n >> m;
    g.assign(n, vector<bool>(m));
    vis.assign(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            g[i][j] = s[j]=='#';
        }
    }
    int maxv = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j]) continue;
            vis[i][j] = true;
            int r = dfs(i,j);
            maxv = max(maxv, r);
            vis[i][j] = false;
        }
    }

    cout << maxv << endl;
    return 0;
} 
