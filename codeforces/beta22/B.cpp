#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, m; cin >> n >> m;

    vector<vector<int>> fenwick(n, vector<int>(m, 0));

    auto sum = [&](int x, int y) -> int {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) -1){
            for(int j = y; j >= 0; j = (j & (j + 1)) -1){
                res += fenwick[i][j];
            }
        }
        return res;
    };

    auto add = [&](int x, int y, int delta) -> void { 
        for(int i = x; i < n; i = i | (i + 1)){
            for(int j = y; j < m; j = j | (j + 1)){
                fenwick[i][j] += delta;
            }
        }
    };

    auto query = [&](int x1, int y1, int x2, int y2) -> int {
        return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1,y1-1);
    };

    for(int i = 0; i < n; i ++) {
        string row; cin >> row;
        for(int j = 0; j < m; j ++){
            if(row[j] == '1') add(i, j, 1);
        }
    }


    int maxv=0;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            for(int k = i; k < n; k ++){
                for(int l = j; l < m; l ++){
                    if(query(i, j, k, l) == 0){
                        // cout << i << " " << j << " " << k << " " << l << " " << 2*(k-i+1) + 2*(l-j+1) << endl;
                        maxv = max(maxv, 2*(k-i+1) + 2*(l-j+1));
                    }
                }
            }
        }
    }

    cout << maxv << endl;
} 
