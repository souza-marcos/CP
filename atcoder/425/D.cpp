#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _

    int n, m; cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m, 1));

    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    set<pair<int, int>> to_process;
    vector<vector<int>> cnt(n, vector<int>(m));
    int res = 0;
    for(int i = 0; i < n ; i ++){
        string s; cin >> s;
        for(int j = 0; j < m; j ++){
            grid[i][j] = s[j] == '.';
        }
    }
    for(int i = 0; i < n ; i ++){
        string s; cin >> s;
        for(int j = 0; j < m; j ++){
            if(grid[i][j]) continue;
            res ++;
            for(auto [newi, newj] : mvs){
                newi += i, newj += j;
                if(min(newi, newj) >= 0 and newi < n and newj < m and grid[newi][newj] == true){
                    if(cnt[newi][newj] == 0) to_process.insert({newi, newj});
                    if(cnt[newi][newj] == 1) to_process.erase({newi, newj});
                    cnt[newi][newj] ++;
                }
            }
        }
    }
    

    // for(auto& row : grid){
    //     for(bool el : row){
    //         cout << (el ? "." : "#")  << " ";
    //     }
    //     cout << endl;
    // }


    while(sz(to_process)){
        set<pair<int, int>> next;
        for(auto [i, j] : to_process){
            grid[i][j] = false; // coloring to black
            res ++;
            for(auto [newi, newj] : mvs){
                newi += i, newj += j;
                if(min(newi, newj) >= 0 and newi < n and newj < m and grid[newi][newj]){
                    if(cnt[newi][newj] == 0) next.insert({newi, newj});
                    if(cnt[newi][newj] == 1) next.erase({newi, newj});
                    cnt[newi][newj] ++;
                }
            }
        }
        to_process=next;
        // for(auto& row : grid){
        //     for(bool el : row){
        //         cout << (el ? "." : "#")  << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "--------------------\n";
    }
    
    cout << res << endl;



    return 0;
} 
