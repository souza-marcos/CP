#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    
    int n; cin >> n;
    vector<string> grid(n);
    for(auto& row : grid) cin >> row;
    vector<tuple<int, int, int>> pq;
    
    pq.push_back({grid[0][0], 0, 0});
    char minel = grid[0][0];
    vector<pair<int, int>> to_compute;
    vector<vector<bool>> ok(n, vector<bool>(n));
    string res;
    for(int i = 0; i < 2*n-1; i++){
        char ff = minel;
        res.push_back(ff);
        to_compute.clear();
        minel = 'Z';
        while(sz(pq)){
            auto [v, a, b] = pq.back(); pq.pop_back(); 
            if(v == ff){
                if(a+1 < n and !ok[a+1][b]){
                    to_compute.push_back({a+1, b});
                    minel = min(minel, grid[a+1][b]);
                    ok[a+1][b] = true;
                } 
                if(b+1 < n and !ok[a][b+1]){
                    to_compute.push_back({a, b+1});
                    minel = min(minel, grid[a][b+1]);
                    ok[a][b+1] = true;
                }
            }
        }

        for(auto [a, b] : to_compute){
            pq.push_back({grid[a][b], a, b});
        }
        to_compute.clear();
    }
    cout << res << endl;
}
