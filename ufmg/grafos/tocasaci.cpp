#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1001; 

int n, m; 
int a[MAX][MAX], dist[MAX][MAX];

bool valid(int i, int j){
    if(i < 0 or i >= n or j < 0 or j >= m) return false;
    return (a[i][j] != 0);
}

int main(){ _
    cin >> n >> m;
    pair<int, int> src, d;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            int &p = a[i][j];
            cin >> p;
            if(p == 2) src = {i, j};
            else if(p == 3) d = {i, j};
        }
    }

    queue<pair<int, int>> q; q.push(src);
    memset(dist, -1, sizeof dist);
    dist[src.first][src.second] = 0;

    vector<pair<int , int>> mvs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        for(auto [newi, newj]: mvs){
            newi += i, newj += j;
            if(valid(newi, newj) and dist[newi][newj] == -1) {
                q.push({newi, newj});
                dist[newi][newj] = dist[i][j] + 1;
            }
        }
    }
    cout << dist[d.first][d.second] + 1 << endl;

    return 0;
} 
