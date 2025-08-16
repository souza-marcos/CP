#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

// prefix sum 2D

int main(){ _
    int n, q; cin >> n >> q;
    
    vector<vector<bool>> grid(n, vector<bool>(n, 0));
    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        for(int j = 0; j < n; j ++)
            grid[i][j] = s[j] == '*';
    }

    /*
    
    In a simple BIT each index correspond to [g(i), i] range where g(i) can be g(i) = i & (i + 1).
    In 2d BIT each pair (i, j) => [(g(i), g(j)) , (i, j)] rect ??
    
    */
    vector<vector<int>> fenwick(n, vector<int>(n, 0));


    // returns [(0,0), (x,y)] summation
    auto sum = [&](int x, int y) -> ll {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1){
            for(int j = y; j >= 0; j = (j & (j + 1)) - 1){
                res += fenwick[i][j];
            }
        }
        return res;
    };

    auto add = [&](int x, int y, ll delta) -> void {
        for(int i = x; i < n; i = i | (i + 1)){
            for(int j = y; j < n; j = j | (j + 1)){
                fenwick[i][j] += delta;
            }
        }
    };

    auto query = [&](int x1, int y1, int x2, int y2) -> ll {
        return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
    };

    auto update = [&](int x, int y) -> void {
        add(x, y, (grid[x][y] ? -1 : + 1));
        grid[x][y] = !grid[x][y];
    };
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(grid[i][j]){
                add(i, j, 1);
            }
        }
    }

    while(q --){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y;
            x --, y--;
            update(x, y);
        } else {
            int y1, x1, y2, x2; cin >> x1 >> y1 >> x2 >> y2;
            y1 --, x1 --, y2 --, x2 --;
            cout << query(x1, y1, x2, y2) << endl; 
        }
    }

    
    return 0;
} 
