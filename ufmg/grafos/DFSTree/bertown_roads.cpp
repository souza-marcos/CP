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
vector<bool> vis;
set<pair<int, int>> marked;
vector<pair<int, int>> res;

int dfs(int p, int v){
    vis[v] = true;
    
    int back_up = 0, back_down = 0, sum = 0;
    for(auto u: g[v]){
        if(u == p) continue;
        if(vis[u]){

            if(marked.count({v, u})) back_down ++;
            else back_up ++, marked.insert({u, v}), res.push_back({v, u});

        }else{
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
    vis.assign(n, false);

    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].push_back(b), g[b].push_back(a);
    }

    dfs(-1, 0);
    assert(sz(res) == m);
    for(auto [v, u] : res) cout << v + 1 << " " << u + 1 << endl;



    return 0;
} 
