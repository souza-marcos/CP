// https://codeforces.com/contest/118/problem/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

vector<vector<int>> g;
vector<int> level;
vector<pair<int, int>> res;

int dfs(int p, int v){
    
    int back_up = 0, back_down = 0, sum = 0;
    for(auto u: g[v]){
        if(u == p) continue;
        
        if(level[u]){

            if(level[u] > level[v]) back_down ++;
            else back_up ++, res.push_back({v, u});

        }else{
            level[u] = level[v] + 1;
            // cout << "Level " << u << "=> " << level[u] << endl;
            res.push_back({v, u});
            int val = dfs(v, u);
            if(val == 0){
                // Has a bridge
                cout << 0 << endl;
                exit(0);
            }
            sum += val;
        }
    }

    return back_up - back_down + sum;
}

int main(){ _
    int n, m; cin >> n >> m;
    g.resize(n);
    level.assign(n, 0);

    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].push_back(b), g[b].push_back(a);
    }
    level[0] = 1;
    dfs(-1, 0);
    assert(sz(res) == m);
    for(auto [v, u] : res) cout << v + 1 << " " << u + 1 << endl;
    return 0;
} 
