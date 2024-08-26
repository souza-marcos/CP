#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define f first
#define s second

int n, m;

bool valid(int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m) return false;
    return true;
}

int main(){ _
    cin >> n >> m;
    vector<string> v(n);
    for(auto &el: v) cin >> el;


    pair<int, int> src;
    for(int i = 0; i < m; i++) if(v[0][i] == 'o') { src = {0, i}; break; } 

    bool vis[n][m]; memset(vis, 0, sizeof vis);

    queue<pair<int, int>> q; q.push(src);
    vector<pair<int, int>> mvs = {{1, 0}, {0, -1}, {0, 1}};
    vis[src.f][src.s] = 1;

    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        // cout << i << " " << j << endl;
        
        if(valid(i + 1, j) and !vis[i + 1][j]){
            if(v[i + 1][j] == '#'){ // Prateleira
                if(!vis[i][j -1]) q.push({i, j - 1}); 
                if(!vis[i][j +1]) q.push({i, j + 1});
                
                vis[i][j - 1] = vis[i][j + 1] = 1;
                v[i][j - 1] = v[i][j + 1] = 'o';
            }
            else if(v[i + 1][j] == '.') q.push({i + 1, j}), vis[i + 1][j] = 1, v[i + 1][j] = 'o';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << v[i][j];
        cout << endl;
    }

    return 0;
} 
