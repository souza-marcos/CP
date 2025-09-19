#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    int n; cin >> n;
    vector<vector<int>> res(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    res[0][0] = 0;
    q.push({0,0});
    vector<pair<int, int>> mvs = {
        {-2, -1}, {-2, +1},
        {+2, -1}, {+2, +1},
        {-1, -2}, {-1, +2},
        {+1, -2}, {+1, +2}
    };

    while(sz(q)){
        auto [i, j] = q.front(); q.pop();
        for(auto [newi, newj] : mvs){
            newi += i, newj += j;
            if(min(newi, newj) >= 0 and max(newi, newj) < n and res[newi][newj] == -1){
                res[newi][newj] = res[i][j] + 1;
                q.push({newi, newj});
            }
        }
    }

    for(auto& row : res){
        for(int el : row) cout << el << " ";
        cout << "\n";
    }

    return 0;
} 
