#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

bool board[8][8];

int search(int line){
    if(line == 8) return 1;
    int cnt = 0;
    for(int j = 0; j < 8; j ++){
        if(board[line][j]){
            vector<pair<int, int>> added;
            for(int row = 0; row < 8; row ++)
                if(board[row][j]) added.push_back({row, j}), board[row][j] = false;

            for(int col = 0; col < 8; col ++)
                if(board[line][col]) added.push_back({line, col}), board[line][col] = false;

            vector<pair<int, int>> mvs = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
            for(auto [x, y] : mvs){
                int cur_x = line, cur_y = j;
                while(cur_x < 8 and cur_x >= 0 and cur_y < 8 and cur_y >= 0){
                    if(board[cur_x][cur_y]) added.push_back({cur_x, cur_y}), board[cur_x][cur_y] = false;
                    cur_x += x, cur_y += y;
                }
            }

            cnt += search(line + 1);
    
            for(auto [x, y] : added){
                board[x][y] = true;
            }
        }
    }

    return cnt;
}

int main(){ _

    for(int i = 0; i < 8; i ++){
        string s; cin >> s;
        for(int j = 0; j < 8; j ++){
            board[i][j] = (s[j] == '.');
        }
    }

    int res = search(0);
    cout << res << endl;
    return 0;
} 
