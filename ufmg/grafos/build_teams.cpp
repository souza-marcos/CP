#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;

vector<vector<int>> g(MAX);
vector<int> vis(MAX, -1);

void dfs(int node, int color){
    vis[node] = color;
    for(auto adj: g[node]){
        if(vis[adj] == color) { cout << "IMPOSSIBLE" << endl; exit(0); }
        else if(vis[adj] == -1) dfs(adj, (color == 1 ? 0: 1));
    }
}

int main(){ _
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a --, b--;
        g[a].pb(b);
        g[b].pb(a);     
    }

    for(int i = 0; i < n; i++){
        if(vis[i] == -1) dfs(i, 0);
    }

    for(int i = 0; i < n; i++){
        cout << (vis[i] + 1) << " ";
    }cout << endl;

    return 0;
} 
