#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

vector<vector<int>> g;
vector<bool> vis;

void dfs(int node){
    cout << node << " ";
    vis[node] = true;
    for(auto adj: g[node]){
        if(!vis[adj]) dfs(adj);
    }
}

int main(){ _

    int n, m; cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 0; i < n; i ++)
        if(!vis[i]) dfs(i);

    return 0;
} 
