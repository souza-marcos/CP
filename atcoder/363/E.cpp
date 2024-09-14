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
int h, w, y; 
vector<vector<int>> grid;
vector<vector<bool>> added;
priority_queue<tuple<int, int, int>> pq; // Val, i, j

vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void add_pos(int i, int j){
    for(auto [newi, newj] : mvs){
        newi += i, newj += j;
        if(newi < 0 or newi >= h or newj < 0 or newj > w) continue;
        if(added[newi][newj]) continue;
        pq.push({-grid[newi][newj], newi, newj});
        added[newi][newj] = true;
    }
}

int main(){ //_
    cin >> h >> w >> y;
    grid.assign(h, vector<int>(w));

    for(auto& row: grid) for(auto& el: row) cin >> el;

    added.assign(h, vector<bool>(w, false));

    for(int i = 0; i < h; i++){
        added[i][0] = added[i][w -1] = true;
        pq.push({-grid[i][0], i, 0});
        pq.push({-grid[i][w-1], i, w-1});
    }
    for(int j = 1; j < w-1; j++){
        added[0][j] = added[h-1][j] = true;
        pq.push({-grid[0][j], 0, j});
        pq.push({-grid[h-1][j], h-1, j});
    }

    // for(auto& row: grid) { 
    //     for(auto& el: row) cout << el << " ";
    //     cout << endl;
    // }

    ll prev = h * w, cur = 0;
    for(int level = 1; level <= y; level++) {
        cur = 0;
        while(!pq.empty()) {
            auto [top, curi, curj] = pq.top();
            top = -top;
            if(top > level) break;
            pq.pop();
            add_pos(curi, curj);
            cur++;
        }
        cout << prev - cur << endl;
        prev -= cur;
    }
    return 0;
} 
