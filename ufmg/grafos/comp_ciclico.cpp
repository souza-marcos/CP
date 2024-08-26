#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 10;
int n, m;
vector<vector<int>> g(MAX);
bool vis[MAX];

bool dfs(int node){
    vis[node] = true;
    bool iscycle = true;
    for(int adj : g[node]){
        if(!vis[adj] and !dfs(adj)) iscycle = false;
    }
    if(g[node].size() != 2 or !iscycle) return false;
    return true;
}

int main(){ _
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i] and dfs(i)) ans ++;
    }

    cout << ans << endl;
    return 0;
} 
