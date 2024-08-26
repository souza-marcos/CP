#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 110;

int n, m; 
char M[MAX][MAX];
vector<vector<bool>> vis; 
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(pair<int, int> pos){
    return pos.f >= 0 && pos.f < n && pos.se >= 0 && pos.se < m && M[pos.f][pos.se] == 'H' && !vis[pos.f][pos.se];
}

pair<int, int> bfs(pair<int, int> s){

    queue<pair<int, int>> q;
    q.push(s), vis[s.f][s.se] = true;

    pair<int, int> v;
    while(!q.empty()){
        v = q.front(); q.pop();
        for(auto w: mov){
            w.f += v.f, w.se += v.se; // new pos 
            if(val(w)){
                q.push(w), vis[w.f][w.se] = true;
            }
        }
    }
    return {v.f + 1, v.se + 1};
}

int main(){ _
    cin >> n >> m;
    vis.resize(n, vector<bool>(m, false));
    pair<int, int> s;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> M[i][j];
            if(M[i][j] == 'o') s = {i, j};
        }
    }
    pair<int, int> ans = bfs(s);

    cout << ans.f << " " << ans.se << endl;

    return 0;
} 
