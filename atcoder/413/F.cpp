#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size() 

int main(){ _ 
    int n, m, k; cin >> n >> m >> k;
    
    vector<vector<int>> grid(n, vector<int>(m, -1));
    vector<vector<int>> pt(n, vector<int>(m, 0));

    vector<pair<int,int>> mvs={{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    queue<tuple<int, int>> q;

    for(int i = 0; i < k; i ++){
        int r, c; cin >> r >> c;
        r --, c--;
        grid[r][c] = 0;
        for(auto [newr, newc] : mvs){
            newr += r, newc += c;
            if(min(newr, newc) >= 0 and newr < n and newc < m and grid[newr][newc] == -1){
                if(pt[newr][newc] ++){
                    q.push({newr, newc});
                }
            }
        }
    }

    ll res = 0;
    while(sz(q)){
        auto [r, c] = q.front(); q.pop();
        if(grid[r][c] != -1) continue;

        vector<int> arr;
        for(auto [newr, newc] : mvs){
            newr += r, newc += c;
            if(min(newr, newc) >= 0 and newr < n and newc < m){
                if(grid[newr][newc] == -1){
                    if(pt[newr][newc] ++)
                        q.push({newr, newc});
                }
                else arr.push_back(grid[newr][newc]);
            }
        }
        
        sort(arr.begin(), arr.end());
        assert(sz(arr) >= 2);
        res += grid[r][c] = arr[1] + 1;
    }
    cout << res << endl;
    return 0;
} 
