#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;

int n, m;
vector<vector<int>> g(MAX);
vector<int> paths(MAX, -1);

int npaths(int u, int v){
    if(u == v) return 1;
    if(paths[u] != -1) return paths[u];
    paths[u] = 0;
    for(auto adj: g[u]) paths[u] += npaths(adj, v);
    return paths[u];
}

int main(){ 
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
    }

    int u, v; cin >> u >> v; u--, v --;
    cout << npaths(u, v) << endl;

    return 0;
} 
