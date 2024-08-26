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

vector<vector<pair<int, int>>> g;
int n, m;

int main(){ _
    cin >> n >> m;
    pair<int, int> cur_pos;
    g.assign(n, vector<pair<int, int>>(m, {-1, 0}));
    char op;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '#') g[i][j].first = -2;
            if(s[j] != '.' and s[j] != '#') cur_pos = {i, j}, op = s[j];
        }
    }

    // Left, down, right, up
    vector<pair<int, int>> mvs = {{ 0, -1}, {1, 0},{0, 1},{-1, 0}};
    int curop = 0;
    if(op == 'D') curop = 1;
    else if(op == 'R') curop = 2;
    else if(op == 'U') curop = 3;
    
    int cnt = 0;
    while(true){
        auto [i, j] = cur_pos;
        if(g[i][j].second & (1 << (curop + 1))){
            break;
        }
        g[i][j].second |= (1 << (curop + 1));
        if(g[i][j].first == -1) cnt ++, g[i][j].first = 1;
        
        // cout << i << " " << j  <<" " << g[i][j].second << endl;
        bool ok = false;
        for(int jmp = 0; jmp < 4; jmp ++){
            auto [newi, newj] = mvs[(curop + jmp) % 4];
            newi += i, newj += j;
            // cout << "NEW POS: " << newi << ", " << newj << endl;

            if(newi < 0 or newi >= n or newj < 0 or newj >= m) continue;
            if(g[newi][newj].first == -2) continue;
            
            ok = true;
            cur_pos = {newi, newj};
            curop = (curop + jmp)% 4;
            break;
        }
        if(!ok) break;
    }
    cout << cnt << endl;

    return 0;
} 
