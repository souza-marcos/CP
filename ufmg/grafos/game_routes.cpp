#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int n, m;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX, 0);
vector<int> order;
vector<ll> paths(MAX, 0);


void dfs(int v){
    vis[v] = true;
    for(int adj: g[v]) if(!vis[adj]) dfs(adj);
    order.push_back(v);
}

int main(){ _
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    paths[0] = 1;
    for(int i = 0; i < n;i ++) if(!vis[i]) dfs(i);

    for(auto it = order.rbegin(); it != order.rend(); ++it){
        if(paths[*it] == 0) continue;
        for(int adj: g[*it]){
            paths[adj] = (paths[adj] + paths[*it])%MOD;
        }
    }

    cout << paths[n -1] << endl;

    return 0;
} 
