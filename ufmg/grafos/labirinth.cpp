#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX 1010

pair<int, int> par[MAX][MAX];
char grid[MAX][MAX];
int n, m;
pair<int, int> start = {-1, -1}, endP = {-1, -1};

bool isValid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m && (grid[i][j] == '.' || grid[i][j] == 'B') );
}

vector<pair<int, int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool bfs(){
    queue<pair<int, int>> q; q.push(start);
    par[start.first][start.second] = start;
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        for(auto [newi, newj]: mov){
            newi += i, newj += j;
            if(isValid(newi, newj) and par[newi][newj].first == -1){
                par[newi][newj] = {i, j};
                q.push({newi, newj});
                if(newi == endP.first and newj == endP.second) return true;
            }
        }
    }
    return false;
}

int main(){ _
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            auto &c = grid[i][j];
            cin >> c; par[i][j] = {-1, -1};
            if(c == 'A') start = {i, j};
            else if(c == 'B') endP = {i, j};
        }
    }

    if (!bfs()) { cout << "NO" << endl; return 0; }
    else cout << "YES\n";

    stack<pair<int, int>> path;
    
    auto cur = endP;

    while(!(cur.first == start.first and cur.second == start.second)){
        path.push(cur); cur = par[cur.first][cur.second];
    }
    
    cout << path.size() << endl;
    cur = start;
    while(!path.empty()){
        auto [i, j] = path.top(); path.pop();
        
        int newi = cur.first - i, newj = cur.second - j;
        if(newi == 0){
            if(newj == -1) cout << "R";
            else cout << "L";
        }else if(newi == 1) cout << "U";
        else cout << "D";
        
        cur = {i, j};
    }
    cout << endl;

    return 0;
} 
